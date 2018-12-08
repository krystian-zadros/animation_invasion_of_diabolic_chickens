#include "shapes.inc"
#include "textures.inc"
#include "colors.inc"
#include "woods.inc"
#include "metals.inc"
#include "obiekty.inc"


#declare przemieszczenie = -clock*40;



sky_sphere {
  pigment {
    gradient z
    color_map {
      [0.5 color <0, 0.74609375, 0.99609375>]
      [1.0 color MidnightBlue]
    }
    scale 2   
  }
  pigment {
    bozo
    turbulence 0.9
    omega 0.7
    color_map {
      [0.0 color rgb <0.85, 0.85, 0.85>]
      [0.1 color rgb <0.75, 0.75, 0.75>]
      [0.5 color rgbt <1,1,1,1>]
      [1.0 color rgbt <1,1,1,1>]
    }
    scale <0.6, 0.3, 0.3>
  }
}


plane {
  y, 0
  pigment {color Green}
}



light_source {
  <0, 15, -45>
  color White
  area_light <30, 0, 0>, <0, 0, 30>, 2, 2
  adaptive 1
  jitter
}
light_source {
  <0, 300, -500>
  color White
}


// kamera z boku z lewej
camera {
  location <-50, 7, 20>
  look_at <-60, 7, 30>
}




       
#macro krowa()
        #local oko = union {
                sphere {
                  <0,0,0>, 0.1
                  pigment {color White}
                }
                sphere {
                  <0,0,0>, 0.06
                  translate <0,0,-0.08>
                  pigment {color Black}
                }       
        }
        #local rog = union {
                blob {
                threshold 0.01
                cylinder {
                  <-0.2,0,0>
                  <0.2,0,0>
                  0.1, 1
                  pigment {color White}
                }
                cylinder {
                  <0,-0.2,0>
                  <0,0.2,0>
                  0.08, 1
                  translate <0.2,0.2,0>
                  pigment {color White}
                }
                }
        }
        #local pyszczek = union {
                
                cylinder {
                  <0,0,-0.3>
                  <0,0,0.3>
                  0.2
                  pigment {color rgb <0.9,0.8,0.8>}
                }
                sphere {
                  <0,0,-0.3>
                  0.22
                  scale <1,1,0.8>
                  pigment {color  rgb <0.9,0.8,0.8>}
                }
        }
        #local glowa = union {
                sphere {
                  <0,0,0>,0.4
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                object {
                  oko
                  translate <-0.2,0.2,-0.35>
                }
                object {
                  oko
                  translate <0.2,0.2,-0.35>
                }
                object {
                  pyszczek
                  translate <0,0,-0.3>
                }
                object {
                  rog
                  translate <0.3,0.2,0>
                }
                object {
                  rog
                  rotate <0,180,0>
                  translate <-0.3,0.2,0>
                }
        }
        #local szyja = union {
                cylinder {
                  <0,-0.2,0>
                  <0,0.2,0>
                  0.2
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                object {
                  glowa
                  translate <0,0.35,0>
                }
        }
        #local wymie = union {
                cylinder {
                  <0,0,-0.2>
                  <0,0,0.2>
                  0.08
                  pigment {color  rgb <0.9,0.8,0.8>}
                } 
        }
        #local wymiona = union {
                sphere {
                  <0,0,0>,0.4
                  pigment {color  rgb <0.9,0.8,0.8>}
                }
                object {
                  wymie
                  rotate <-5,10,0>
                  translate <-0.15,0.15,-0.35>
                }                     
                object {
                  wymie
                  rotate <-5,10,0>
                  translate <-0.15,-0.15,-0.35>
                }
                object {
                  wymie
                  rotate <-5,-10,0>
                  translate <0.15,0.15,-0.35>
                }
                object {
                  wymie
                  rotate <-5,-10,0>
                  translate <0.15,-0.15,-0.35>
                }
        }
        #local lydka = union {
                cylinder {
                  <0,-0.25,0>,<0,0.25,0>,0.1
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                box {
                  <-0.1,-0.12,-0.1>,<0.1,0.12,0.1>
                  translate <0,-0.25,0>
                  pigment {color Black}
                }
        }
        #local kolano = union {
                sphere {
                  <0,0,0>, 0.11
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                object {
                  lydka
                  translate <0,-0.25,0>
                  rotate <-20,0,0>
                }
        }
        #local udo = union {
                cone {
                  <0,0.3,0>, 0.3
                  <0,-0.3,0> 0.1
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                object {
                  kolano
                  translate <0,-0.3,0>
                }
        }
        #local noga = union {
                sphere {
                  <0,0,0>, 0.3
                  texture { pigment{image_map { png "lata_krowy.png"}}}                 
                }
                object {
                  udo
                  translate <0,-0.3,0>
                }
        }
        #local przedramie = union {
                cylinder{
                  <0,-0.2,0>, <0,0.2,0>, 0.1
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                box {
                  <-0.1,-0.12,-0.1>,<0.1,0.12,0.1>
                  translate <0,-0.25,0>
                  pigment {color Black}
                }
        }
        #local lokiec = union {
                sphere {
                  <0,0,0>, 0.12
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                object {
                  przedramie
                  translate <0,-0.2,0>
                  rotate <45,0,0>
                }
        }
        #local ramie = union {
                cylinder{
                  <0,-0.3,0>, <0,0.3,0>, 0.1
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                object {
                  lokiec
                  translate <0,-0.3,0>
                }
        }
        #local korpus = union {
                sphere {
                  <0,0,0>, 1
                  scale <0.5,1,0.7>
                  texture { pigment{image_map { png "lata_krowy.png"}}}
                }
                object {
                  szyja
                  translate <0, 1 ,0>
                }
                object {
                  wymiona
                  translate <0,-0.3,-0.5>
                }
                object {
                  noga
                  rotate <45*sin(clock*360),0,0>
                  translate <0.22,-0.8,0>
                }
                object {
                  noga
                  rotate <-45*sin(clock*360),0,0>
                  translate <-0.22,-0.8,0>
                }
                object {
                  ramie
                  translate <0,-0.2,0>
                  rotate <-45*sin(clock*360),0,0>
                  rotate <0,-10,0>
                  rotate <0,0,30>
                  translate <0.3,0.8,0>
                }
                object {
                  ramie
                  translate <0,-0.2,0>
                  rotate <45*sin(clock*360),0,0>
                  rotate <0,10,0>
                  rotate <0,0,-30>
                  translate <-0.3,0.8,0>
                }
        }
        object {korpus}
    
    
#end






/*
  ****************************************************************************************
  *************************   FUNKCJA MAIN   *********************************************
  ****************************************************************************************
*/


object {
        kurka()
        //translate <-60, 5, 30>
        translate <-60, 5, 50+przemieszczenie>
}
object {
        kurka()
        //translate <-60, 5, 30>
        translate <-68, 5, 58+przemieszczenie>
}
object {
        kurka()
        //translate <-60, 5, 30>
        translate <-64, 5, 66+przemieszczenie>
}


// ******  SCENERIA  ******

        
        object {
          dom(-10)
          scale <10,10,10>
          rotate <0, -90, 0>
          translate <-100, 20, 50>
        }
        object {
          drzewo()
          scale <10,10,10>
          rotate <0, 20, 0>
          translate <-90, 6, 110>
        }
        object {
          grabie()
          scale <3,3,3>
          rotate <-90,0,0>
          rotate <0,-90,0>
          rotate <0,0,20>
          translate <-73, 6, 35>
        }
        object {
          konewka()
          scale <11,11,11>
          translate <-74, 1, 42>
        }


object {
  krowa()
  scale <3,3,3>
  translate <-60, 6, 40+przemieszczenie>
}