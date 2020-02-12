# TurtleBot-Project

Hola chicos, voy a comentar algunos puntos de lo que he hecho y a comentar algunas cosas que creo que son interesantes.

Antes de nada creo que a partir del próximo update deberiamos de actualizar este README en inglés para quedar un poco mas profesional, pero por ahora lo usaré como introducción.

En el proyecto podeis encontrar la carpeta src donde teneis varios packages (la mayoría se utilizan aunque queda limpiarla un poco), el interesante es turtlebot_2dnav. En este podeis encontrar una carpeta Param con los parámetros necesarios para el Move_Base y una carpeta launch donde esta el fichero que he creado para poder probar la conexión entre diferentes bloques, estos son:

Turtlebot_world: Lanza gazebo (proporciona odometría) y un modelo (URDF) de Kobuki (posee una cámara cuyos datos convierte a Scanner (Ejercicio 1)), además lanza un Nodelet manager que crea topics del tipo Mobile_base para mover al robot.

Gmapping_Demo: Lanza Gmapping para crear el mapa a partir del Scanner, localizando a la vez el robot en este. Publica la info en un topic /Map y transforma de Odometría a Posición en el Mapa (haciendo Scan-Matching).

Explore: Para explorar de forma autónoma es necesario conocer que zonas son interesantes para mapear todo el entorno, para ello se utilizan técnicas basadas en Frontiers y Explore_lite realizar la busqueda mediante un algorítmo greedy (busca la mejor opción en cada instante, unicamente a partir de la información local), este nodo recibe tanto la posición del robot (TF) como el mapa y envia goals al Move_Base (a través de un servicio que este facilita). (Ejercicio 2)

Move_Base: Se encarga de la navegación, en nuestro caso recibe goals y comunica a la base del robot el Twist necesario en cada instante para alcanzar este goal, para ello se necesita un plan local y un plan global. En nuestro caso el plan global es Navfn (Ejercicio 3) y el plan local (DWA). Para enviar el Twist desde el cmd_vel que publica se ha remapeado el topic al que publicaba para poder recibirlo en el topic al que la base está suscrita.


A continuación os dejo algunos ejercicios que merece la pena echarle un ojo:

Ejercicio 1: El kobuki simulado no tiene lidar, usa la información de una cámara para simular un Scanner y esto es poco útil, he visto algun ejemplo de como introducir un lidar (lo suyo seria el RPLidar) pero se necesita investigar y ver como se modifican los URDF que se pueden encontrar en internet y como tocar el turtlebot_world para que en vez de lanzar como sensor la cámara use el Lidar.

Ejercicio 2: El package de Explore_lite cumple con nuestro requisito pero estaría bien echarle un ojo a algunos packages como Hector_mapping o Cartographer, lo suyo sería que escogieriais alguno que vieseis viable y realizaseis un análisis de si es mejor usar ese o combinar Gmapping + Alguno basado en frontiers (como este). 

Ejercicio 3: No he estudiado muy bien como funciona Navfn y alguna vez los frontiers se salen del global_costmap, es posible que no se necesite tocar nada pero estaría bien estudiarlo a fondo para ver que se puede hacer para posteriormente modificar los costmaps.

Mi frente de trabajo va a ser centrarme en cada nodo específico y conseguir realizar pequeñas modificaciones, ahora voy a intentar cambiar el mapa por el Willow garage y poder hacer lo que comentaba en el ejercicio 1. 



Problemas que me han ido surgiendo:

Comentado lo del remapeo que hice para el Move_base tambien he tenido que instalar algunos packages (generalmente con turtlebot_apps está todo).

Para que Frontiers y Move_base funcionasen mínimamente he tenido que tocar algunos parámetros de los ficheros del PARAM para permitir el allow_unknown para poder ir a zonas no mapeadas. Tambien he tenido que tocar las dimensiones del path local para poder ampliarlo ya que en el mapa estándar que lanza Turtlebot_world no hay muchas referencias y marca algunos puntos un poco locos. 

Un problema que me tuvo bastante lastrado era que explore_lite enviaba constantemente el mismo frontiers y Move_base respondía que ya lo había alcanzado, esto parece ser que se debía a que el local_planner tiene una tolerancia cuando el goal está cerca de un objeto y avisaba de que se encontraba en la posición sin estar realmente en ella (de base eran 0.5m lo que es bastante considerable) por lo tanto ambos no se entendían.

Ahora mismo es capaz de mapear parte del entorno y mostrar los frontiers (RVIZ), pero no funciona de manera óptima y falla a veces con el Scan_Matching, parece que estoy lanzando dos veces el mismo scan o simplemente el TF no funciona del todo bien. Por ello voy a intentar trabajar mas bloque a bloque y resolver problemas pequeños, almenos este estudio de los bloques a alto nivel nos permite establecer una base por la que empezar e ir creando sobre ella.

Esto es todo por ahora, cualquier duda la comentamos y si quereis podeis modificar este documento para hacer algún comentario. 

Como os he comentado cuando hayais tenido tiempo de leer todo me pondré a hacer un README más técnico en inglés mas orientado a una fútura exposición y documentando lo que hemos hecho para arreglar los errores que nos han ido surgiendo.


