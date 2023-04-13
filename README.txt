*INFO: El archivo output.txt con las letras del texto ordenadas se genera en la carpeta build.

*POSIBLES ERRORES: 
- Funciona correctamente en un Windows con la versión 6.4 del QT. Han habido problemas a la hora de exportar a Linux.
- Es posible encontrarse con un error relacionado con el QDebug. Simplemente, añada "#include <QDebug>" al inicio del .cpp.
- Es posible recibir un error en el cual no se pueda igualar "directorioEntrada" o "directorioSalida" = NULL. En el caso de Ovidiu (Windows, QT ver. 6.4) funciona,
  pero no ha funcionado en los ordenadores de Xu ni de Diego. En este caso, simplemente comentar las líneas en las que devuelva este error. Las funcionalidades afectadas   serían el botón de Reset en el algoritmo de imágenes, ya que no deseleccionaría la ruta al resetear, por tanto podrías volver a ejecutar aún habiéndo reseteado.

*ENLACE DEL VÍDEO: https://drive.google.com/file/d/1Yljz5uqk-wSW6f-5ZPuSx0oOsAG8fKGV/view?usp=share_link
