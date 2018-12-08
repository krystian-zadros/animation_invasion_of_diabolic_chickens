#include "shapes.inc"
#include "textures.inc"
#include "colors.inc"
#include "woods.inc"

//#local Kamera = <0, 5, -20>;
#local Kamera = <0, 5, -25>;



/*background {
  color <0.5, 0.85, 0.98>
}*/

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
    }
    scale <0.6, 0.3, 0.3>
  }
}




plane {
  y, 0
  pigment {
    color Green
  }
  /*normal {
    wrinkles 1
  } */
}


// oswietlenie planu
/*light_source {
  <-200, 1000, 200>
  color White // <0.99, 0.99, 0.83>  // color <0.99, 0.99, 0.73047>
}*/
/*light_source {
  Kamera + <0, 200, -20>
  color White 
}*/

light_source {
  Kamera + <0, 10, -20>
  color White
  area_light <30, 0, 0>, <0, 0, 30>, 5, 5
  adaptive 1
  jitter
}
light_source {
  Kamera + <0, 200, -20>
  color White
}



#local moment_zestrzelenia = array[4] { 4.0, 8.0, 3.0 , 6.0};



//  ***   Ruch strzelby   ***
// Kolejno zestrzeliwane sa i = {2, 0, 3, 1}
#if ((clock <= moment_zestrzelenia[1] + clock_delta) & (clock >= moment_zestrzelenia[1] - clock_delta))
        light_source {
          //Kamera - <0, 2, 0>
          Kamera + <0, 0, 18>
          color Yellow 
        }
#else
        #if ((clock <= moment_zestrzelenia[3] + clock_delta) & (clock >= moment_zestrzelenia[3] - clock_delta))
                        light_source {
                          Kamera + <0, 0, 18>
                          color Yellow 
                        }
        #else
                #if ((clock <= moment_zestrzelenia[0] + clock_delta) & (clock >= moment_zestrzelenia[0] - clock_delta))
                        light_source {
                          Kamera + <0, 0, 18>
                          color Yellow 
                        }
                #else
                        #if ((clock <= moment_zestrzelenia[2] + clock_delta) & (clock >= moment_zestrzelenia[2] - clock_delta) )
                                light_source {
                                  Kamera + <0, 0, 18>
                                  color Yellow 
                                }
                        #end
                #end
       #end 
#end














// kamera z przodu
camera {
  //location <0, 5, -20>
  location Kamera
  //location <0, 50, 0>
  look_at <0, 5, 0>
}

/*// kamera z tylu
camera {
  location <0, 1, 10>
  look_at <0, 0, 0>
}*/

/*// kamera z gory
camera {
  location <0, 60, 6>
  look_at <0, 5, 6>
}*/

/*// kamera z dolu
camera {
  location <0, -30, 0>
  look_at <0, -5, 0>
}*/

/*// kamera z boku z lewej
camera {
  location <-10, 1, 0>
  look_at <0, 0, 0>
}*/

/*// kamera z boku z prawej
camera {
  location <30, 5, 0>
  look_at <0, 5, 0>
}*/


/*
  ****************************************************************************************
  ****************************   MACRO DOM   *********************************************
  ****************************************************************************************
*/


#macro dom(obrot_y)
        #local kolor_scian = <0.99609375, 0.66796875, 0.34765625>;  // kolor zolty szafranowy 	
        #local glowna_bryla = union {
        // 7.4 x 4 x 5.4
                  cylinder {
                    <-1.5, -2, 0>
                    <-1.5, 1.8, 0>
                    2
                    pigment {color kolor_scian}
                  }
                  box {
                    <-1.5, -2, -2>
                    <2, 1.8, 2>
                    pigment {color kolor_scian}
                  } 
                
                  // dach
                  cylinder {
                    <-1.5, 1.8, 0>
                    <-1.5, 2, 0>
                    2.2
                    pigment {color rgb <0.5, 0, 0>}
                  }
                  box {
                    <-1.7, 1.8, -2.7>
                    <2.2, 2, 2.7>
                    pigment {color rgb <0.5, 0, 0>}
                  }
        }

        #local puste = union {
          // wnetrze budynku        
                cylinder {
                    <-1.5, -1.9, 0>
                    <-1.5, 1.7, 0>
                    1.9
                    //pigment {color Red}
                }
                box {
                  <-1.5, -1.9, -1.9>
                  <1.9, 1.7, 1.9>
                  //pigment {color Green}
                }
          // drzwi
                box {
                   <1, -1.9, -2.65>
                   <1.8, -0.3, -1.8>
                }
          // okna
            // gorne
                box {
                  <0.4, 0.65, -2.26>
                  <1.4, 1.5, -1.8>
                }
                box {
                  <-1, 0.9, -2.26>
                  <0, 1.5, 2.05>
                }
                // boczne
                box {
                  <-5, 0.9, -0.5>
                  <5, 1.5, 0.5>
                }
            // dolne
                box {
                  <-1, -0.9, -2.26>
                  <0, -0.2, 2.05>
                }
                // boczne
                box {
                  <-5, -0.9, -0.5>
                  <5, -0.2, 0.5>
                }               
         
        }
        
        #local balkon = union{
                box {
                  <-0.9, -0.1, -0.7>
                  <0.9, 0.1, 0.7>
                  pigment {color rgb kolor_scian}
                }
                cylinder {
                  <-0.9, 0.5, -0.6>
                  <0.9, 0.5, -0.6>
                  0.06
                  pigment {color Brown}
                }
                #local i=-0.82;
                #while (i<=0.82)
                        cylinder {
                          <i, 0.1, -0.6>
                          <i, 0.5, -0.6>
                          0.05
                          pigment {color rgb <0.5, 0, 0>} // kolor rdzawy
                        }
                        #local i= i+0.3;
                #end
        }
        #local parapet = union {
          box {
            <-0.55, -0.1, -0.15>
            <0.55  0.1,  0.15>
            //pigment {color rgb <0.99609375, 0.95703125, 0.88671875>} // kolor perlowy
            pigment {color rgb <0.5, 0, 0>}
          }
        }
        
        
        #local drzwi = union {
                box {
                  <-0.4, -0.8, -0.05>
                  <0.4, 0.8, 0.05>
                  pigment {color rgb <0.5, 0, 0>} // kolor rdzawy
                }
        }
        
        
        #local szkielet_domu = difference {
                        #object {glowna_bryla}
                        #object {puste}
        }
        
        
        #local wszystko = union {
                object {szkielet_domu}
                object {balkon
                        translate <1, 0.5, -2>}
                object {drzwi
                        translate <1.37, -1.1, -2>}
                object {parapet
                        translate <-0.5, 0.8, -2.2>}
                object {parapet
                        translate <-0.5, -0.9, -2.2>}
       }
       object {wszystko rotate <0,  obrot_y, 0>}
#end



box {
<-100, -100, -100>
<-99, -99, -99>
}




/*
  ****************************************************************************************
  **************************   MACRO KURKA   *********************************************
  ****************************************************************************************
*/



#macro kurka()
        #local kolor_pior = <0.56640625 , 0.3203125 , 0.1796875>; // kolor orzechowy zlocisty
        #local kolor_dzioba = <0.99609375, 0.8359375, 0.30078125>;
        #local kolor_glowy = <0.80078125 , 0.333984375 , 0>;
        
        #local oko = union {
                sphere {
                  <0,0,0>
                  0.2
                  finish {
                    ambient 0.9  // jaka czesc przyjmowanego swiatla bedzie odbita
                  }
                  pigment {color Red}
                }
                sphere {
                  <0.0.0>
                  0.1
                  translate <0, 0, -0.15>
                  pigment {color Black}
                }
        }
        
        
        #local glowa = union {
                // czaszka
                sphere {
                  <0,0,0>
                  0.8
                  pigment {color kolor_glowy}
                }
                // dziob
                box {
                  <-0.3, -0.15, -0.4>
                  <0.3, 0.15, 0.4>
                  translate <0, -0.2, -1>
                  pigment {color rgb kolor_dzioba}
                }
                // grzebien
                sphere {
                  <0, 0, 0>
                  0.6
                  scale <0.3, 1, 1>
                  translate <0, 0.8, 0>
                  pigment {color Red}
                }
                // oko prawe
                object {
                  oko
                  translate <-0.4, 0.2, -0.6>
                }
                // oko lewe
                object {
                  oko
                  translate <0.4, 0.2, -0.6>
                }
        }
        
        #local szyja = union {
                  cone {
                    <0 , -0.75, 0>, 0.8
                    <0 , 0.75, 0>, 0.25
                    pigment {color rgb kolor_glowy}  // kolor rudy
                  }
                  object {
                    glowa
                    rotate <90, 0, 0>
                    translate <0, 1.1, 0>
                  }
        }


        #local stopa = union {
                box {
                  <-0.5, -0.2, -1>
                  <0.5, 0.2, 1>
                  pigment {color rgb kolor_dzioba}
                }
        }
        
        
        #local lydka = union {
                 cylinder {
                   <0, -0.6, 0>
                   <0, 0.6, 0>
                   0.2
                   pigment {color rgb kolor_dzioba}
                 }
                 
                 object {
                   stopa
                   //rotate <-30, 0, 0>
                   translate <0, -0.62, -0.7>
                 }
        }
        
        
        
        #local udo = union {
                  cone {
                    <0 , -0.75, 0>, 0.25
                    <0 , 0.75, 0>, 0.8
                    pigment {color rgb kolor_pior}
                  }
                  object {
                    lydka
                    translate <0, -1.3, 0>
                  }
        }
        
        
        #local skrzydlo = union {
                sphere {
                  <0,0,0>
                  2
                  scale <1, 0.5, 0.2>
                  pigment {color rgb kolor_pior}
                }
        }

        #local kolec = union {
                cone {
                  <0, 0, -1.5>, 0.4
                  <0, 0, 1.5>, 0
                  pigment {color Red}
                }
        }

        #local korpus = union {
                lathe {
                  cubic_spline
                  6
                  <0, -2>, <1.1, -1.5>, <1.7, -0.5>, <1, 1>, <0.5, 1.7>, <0.4, 2>
                  pigment {color rgb kolor_pior}
                }
                
                object {
                  kolec
                  scale <0.8, 0.8, 0.8>
                  translate <0, 0, 1.5>
                  rotate <-20, 0, 0>
                  translate <0, 1, -0.2>
                }
                object {
                  kolec
                  translate <0, 0, 1.5>
                  rotate <-10, 0, 0>
                  translate <0, 0.5, 0.5>
                }
                object {
                  kolec
                  translate <0, 0, 1.5>
                  rotate <0, 0, 0>
                  translate <0, -0.2, 0.8>
                }
                  
                object {
                  szyja
                  translate <0, 1.95, 0>
                }
        
                object {
                  udo
                  rotate <0, 0, -5>
                  translate <-0.7, -1.5, 0>
                }
                object {
                  udo
                  rotate <0, 0, 5>
                  translate <0.7, -1.5, 0>
                }
                // skrzydlo prawe
                object {
                  skrzydlo
                  translate <-1, 0, 0>
                  rotate <0, 60*sin(clock*120), 0>     // RUCH SKRZYDEL
                  translate <-2.5, 0.7, 0>
                }
                // skrzydlo lewe
                object {
                  skrzydlo
                  translate <1, 0, 0>
                  rotate <0, -60*sin(clock*120), 0>     // RUCH SKRZYDEL
                  translate <2.5, 0.7, 0>
                }  
        }
        
        
        object {korpus} 
#end




/*
  ****************************************************************************************
  ************************   MACRO DRZEWO   **********************************************
  ****************************************************************************************
*/
#macro drzewo()
        #local korona = sphere {
          <0,0,0>
          0.4
          pigment {color rgb <0.1328125, 0.54296875 , 0.1328125>}
          normal {
            bumps 1
            scale 0.1
          }
        }
        #local galaz = union {
                cylinder {
                  <0, -0.9, 0>
                  <0, 0.9, 0>
                  0.1
                  pigment {color Brown}
                }
                object {
                  korona
                  translate <0, 0.5, 0>
                } 
        }
        #local pien = union {
                cylinder {
                  <0, -1, 0>
                  <0, 1, 0>
                  0.4
                  pigment {color Brown}
                }
                // wydluzenia pnia
                object {
                  galaz
                  scale <1.5, 1.5, 1.5>
                  translate <0, 1.5, 0>
                  rotate <15, 0, 20>
                  translate <-0.2, 0.2, 0>
                }
                object {
                  galaz
                  scale <2, 1.7, 2>
                  translate <0, 1.7, 0>
                  rotate <5, 0, -10>
                  translate <-0.2, 0.2, 0>
                }
                // mniejsze galezie
                object {
                  galaz
                  translate <0, 0.6, 0>
                  rotate <0, 0, 40>
                  //rotate <0, 90, 0>
                  translate <-0.2, 0, 0>
                }
                object {
                  galaz
                  translate <0, 0.8, 0>
                  rotate <0, 0, 40>
                  rotate <0, 90, 0>
                  translate <0, 0, -0.2>
                }
                object {
                  galaz
                  translate <0, 0.9, 0>
                  rotate <0, 0, -40>
                  translate <-0.2, 0.2, 0>
                }
                object {
                  galaz
                  translate <0, 0.9, 0>
                  rotate <0, 0, -40>
                  rotate <0, 40, 0>
                  translate <-0.2, 0.2, 0>
                }
        }
        object {
          pien
        }
#end








/*
  ****************************************************************************************
  ************************   MACRO STRZELBA   ********************************************
  ****************************************************************************************
*/

#macro strzelba()
        #local kolor_strzelby = Grey;
        #local rekojesc = union {
                cone {
                  <0, 0, -2>, 0.5
                  <0, 0, 2>, 0.3
                  scale <0.8, 1, 1>
                  pigment {color Brown}
                }        
        }
        #local celownik = union {
                torus {
                  0.3, 0.05
                  scale <1, 0.5, 1>
                  pigment {color kolor_strzelby}
                }
                box {
                  <-0.03, -0.07, -0.3>
                  <0.03, 0.07, 0.3>
                  pigment {color kolor_strzelby}
                }
                box {
                  <-0.3, -0.07, -0.03>
                  <0.3, 0.07, 0.03>
                  pigment {color kolor_strzelby}
                }
        }
        #local glownia = union {
                // same te rurki przez ktore przechodza pociski
                difference {
                        union {
                                cylinder {
                                  <-0.25, 0, -3>
                                  <-0.25, 0, 3>
                                  0.3
                                  pigment {color kolor_strzelby}
                                }
                                cylinder {
                                  <0.25, 0, -3>
                                  <0.25, 0, 3>
                                  0.3
                                  pigment {color kolor_strzelby}
                                }
                        }
                        union {
                                cylinder {
                                  <-0.25, 0, -2.9>
                                  <-0.25, 0, 3.1>
                                  0.2
                                  pigment {color kolor_strzelby}
                                }
                                cylinder {
                                  <0.25, 0, -2.9>
                                  <0.25, 0, 3.1>
                                  0.2
                                  pigment {color kolor_strzelby}
                                }    
                        }
                }
                
                object {
                  celownik
                  rotate <90, 0, 0>
                  translate <0, 0.7, 3>
                }
                object {
                  rekojesc
                  translate <0,0,-2>
                  rotate <-3, 0, 0>
                  translate <0, 0, -3>
                }
        }
        object {glownia}
#end




/*
  ****************************************************************************************
  *************************   FUNKCJA MAIN   *********************************************
  ****************************************************************************************
*/

object {
  dom(-10)
  scale <10,10,10>
  translate <-40 ,0, 100>
}
object {
  dom(-50)
  scale <10,10,10>
  translate <30 ,0, 150>
}

object {
  drzewo()
  scale <7,7,7>
  translate <30, 7, 50>
}








#local i = 0;
#while (i<4)

        #local kres_lewy = array[4] {-27, 18, -20, 22};
        #local kres_prawy = array[4] { kres_lewy[0] * (-1) , kres_lewy[1] * (-1) , kres_lewy[2] * (-1) , kres_lewy[3] * (-1) };
        #local zestrzelona = array[4] { false, false, false , false };
        #local polozenie_x = array[4] { kres_lewy[0] , kres_lewy[1] , kres_lewy[2] , kres_lewy[3] };
        #local polozenie_y = array[4] { 12, 9, 4 , 6}
        #local zwrot = array[4] { 1, -1, 1 , -1};
        #local r_bum = 1;
        #local moment_zestrzelenia = array[4] { 4.0, 8.0, 3.0 , 6.0};
        #local moment_znikniecia = array[4] { 5.0, 9.0, 4.0 , 7.0};
        #local polozenie_x_zestrzelenia = array[4] { 2, -8, -2 , -3};
        
        
        #if (clock <= moment_znikniecia[i])
                #if (clock<=moment_zestrzelenia[i])
                        // Funkcja przemieszczenia na OX
                        #local polozenie_x[i] = polozenie_x[i] + zwrot[i]*((clock/10) * (abs(kres_prawy[i]) + abs(kres_lewy[i])));
                        
                        object {kurka()
                          rotate <0,-90*zwrot[i], -90*zwrot[i]>
                          translate <polozenie_x[i] , polozenie_y[i], 6>
                        }
                #else
                        object {kurka()
                          rotate <-90*zwrot[i], -90, 0>
                          translate <polozenie_x_zestrzelenia[i] , polozenie_y[i], 6>
                        }   
                #end
        #end
        
        
        #if ((clock>=moment_zestrzelenia[i]) & (clock<=moment_znikniecia[i]))
                object {kurka()
                  rotate <-90*zwrot[i], -90, 0>
                  translate <polozenie_x_zestrzelenia[i] , polozenie_y[i], 6>
                  }
                sphere {
                  <polozenie_x_zestrzelenia[i] , polozenie_y[i], 6>
                  r_bum + (clock*0.4)
                  pigment {color Yellow}
                }
        #end
        
        #local i = i+1;


//  ***   Ruch strzelby   ***
// Kolejno zestrzeliwane sa i = {2, 0, 3, 1}
#if ((clock <= moment_zestrzelenia[1]) & (clock > moment_zestrzelenia[3]))
        object {
          strzelba()
          scale <5,5,5>
          rotate <-16 , 5*(clock/moment_zestrzelenia[1]) , 0>
          translate Kamera + <0, -5, 3>
        }
#else
        #if ((clock < moment_zestrzelenia[3]) & (clock > moment_zestrzelenia[0]))
                object {
                  strzelba()
                  scale <5,5,5>
                  rotate <-6 , 5*(clock/moment_zestrzelenia[3])+3 , 0>
                  translate Kamera + <0, -5, 3>
                }
        #else
                #if ((clock < moment_zestrzelenia[0]) & (clock > moment_zestrzelenia[2]))
                        object {
                          strzelba()
                          scale <5,5,5>
                          rotate <-15 , 5*(clock/moment_zestrzelenia[0]) , 0>
                          translate Kamera + <0, -5, 3>
                        }
                #else
                       // #if (clock < moment_zestrzelenia[2])
                                object {
                                  strzelba()
                                  scale <5,5,5>
                                  rotate <-3 , -5*(clock/moment_zestrzelenia[2]) , 0>
                                  translate Kamera + <0, -5, 3>
                                }
                        
                #end
       #end 
#end



#end // koniec while