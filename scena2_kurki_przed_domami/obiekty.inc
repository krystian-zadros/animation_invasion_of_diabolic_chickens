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
                  scale <0.5, 1, 1>
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
                  <-0.3, -0.15, -0.5>
                  <0.3, 0.15, 0.5>
                  translate <0, -0.2, -0.55>
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
                rotate <-90,0,0>
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
                  <-0.5, -0.1, -0.6>
                  <0.5, 0.1, 0.6>
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
                   rotate <-30, 0, 0>
                   translate <0, -0.65, -0.4>
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
                object{
                  siekiera()
                  translate <0,0,-0.1>
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
                  rotate <0, 50*sin(clock*180), 0>     // RUCH SKRZYDEL
                  //rotate <0, 60*sin(mod(clock*120, 270)), 0>     // RUCH SKRZYDEL
                  translate <-2.5, 0.7, 0>
                }
                // skrzydlo lewe
                object {
                  skrzydlo
                  translate <1, 0, 0>
                  rotate <0, -50*sin(clock*180), 0>     // RUCH SKRZYDEL
                  //rotate <0, -60*sin(mod(clock*120, 270)), 0>     // RUCH SKRZYDEL
                  translate <2.5, 0.7, 0>
                }  
        }
        
        
        object {korpus} 
#end




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










/*
  ****************************************************************************************
  ************************   MACRO TRAKTOR   *********************************************
  ****************************************************************************************
*/

#macro traktor(_obr)
        #local kolo = union {

        // *** opona + wycinam cylinder na felgi ***       
                difference {
                        torus {
                          0.6, 0.4
                          rotate <0, 0, 90>
                          pigment {color rgb<0.3, 0.3, 0.3>}
                        }
                        cylinder {
                          <-0.45, 0, 0>
                          <0.45, 0, 0>
                          0.549
                          pigment {color rgb <0.7, 0.7, 0.7>}
                        }
                }
                
                #local r=0;
        
                #while (r<=360)
                // *** opona ***
                    intersection {
                            difference {
                                    box {
                                      <-0.4, -0.05, -1.1>
                                      <0.4, 0.05, 1.1>
                                      rotate <r, 0, 0>
                                      pigment {color rgb<0.3, 0.3, 0.3>}
                                    }
                                    cylinder {
                                      <-1,0,0>, <1,0,0>, 0.6
                                    }
                            } // koniec difference
                            torus {
                                0.7, 0.43
                                rotate <0, 0, 90>
                                pigment {color rgb<0.3, 0.3, 0.3>}
                            }
                    }
                    
                // *** felgi ***
                    difference {
                            cylinder {
                              <-0.4, 0, 0>
                              <0.4, 0, 0>
                              0.55
                              pigment {color rgb <0.7, 0.7, 0.7>}
                            }
                            union {
                                    cylinder {
                                      <-0.5, 0, 0>
                                      <-0.3, 0, 0>
                                      0.4
                                      pigment {color rgb <0.7, 0.7, 0.7>}
                                    }
                                    cylinder {
                                      <0.5, 0, 0>
                                      <0.3, 0, 0>
                                      0.4
                                      pigment {color rgb <0.7, 0.7, 0.7>}
                                    }
                                    // wejscia do odkrecenia felg
                            } // koniec union
                    }
                    
                        #local r = r + 40;
                #end  // koniec while
        
        }  // koniec local 'kolo'
        
        
        // 2 elementy kierownicy
        #local kierownica = union {
                torus {
                  0.5, 0.1
                  pigment {color Grey}
                  scale <1, 0.5, 1>
                  rotate <90, 0, 0>
                }
                
                sphere {
                  <0,0,0>
                  0.2
                  pigment {color Grey}
                  scale <1, 1, 0.25>
                }
                
                box {
                  <-0.5, -0.1, -0.04>
                  <0.5, 0.1, 0.04>
                  pigment {color Grey}
                }
                box {
                  <-0.5, -0.1, -0.04>
                  <0.5, 0.1, 0.04>
                  rotate <0, 0, 90>
                  pigment {color Grey}
                }
        }
        #local to_cos_na_czym_stoi_kierownica = union {
                cylinder {
                  <0, 0, -0.6>
                  <0, 0, 0.6>
                  0.08
                  //rotate <0, 0, 90>
                  pigment {color Grey}
                }
                object {
                  kierownica
                  rotate <0, 0, sin(clock*10)>
                  translate <0, 0, 0.65>
                }
        }
        
        
        // fotel
        #local siedzenie_traktora_siedzisko = union {
                box {
                  < -0.5,  -0.05, -0.2>
                  < 0.5, 0.05, 0.2>
                  pigment {color Grey}
                }
        }
        #local siedzenie_traktora_oparcie = union {
                box {
                  < -0.5, -0.5, -0.1>
                  < 0.5, 0.5, 0.1>
                  pigment {color Grey}
                }
                object {
                  siedzenie_traktora_siedzisko
                  translate <0, -0.35, -0.25>
                }
        }
        // kabina traktora
        #local kabina = union {
                difference {
                        box {
                          < -0.7, -1, -0.9>
                          < 0.7, 1, 0.9>
                          pigment {color Red}
                        }
                        
                        union {
                                // skosna tylna sciana
                                box {
                                  <-2.7, -1.3, -0.6>
                                  < 2.7, 1.3, 0.6>
                                  rotate <-10, 0, 0>
                                  translate <0, 0, 1.5>
                                  pigment {color Red}
                                }
                                // przednia i tylna szyba
                                box {
                                  < -0.6, -0.3, -2>
                                  < 0.6, 0.9, 2>
                                  pigment {color Red}
                                }
                                // szyby boczne
                                // UWAGA! Trzeba zrobic drzwi!
                                box {
                                  < -1, -0.6, -0.8>
                                  < 1, 0.9, 0.3>
                                  pigment {color Red}
                                }
                        }
                }
                
                object {
                  to_cos_na_czym_stoi_kierownica
                  scale <0.3, 0.3, 0.3>
                  translate <0, 0, 0.15>
                  rotate <-40,0, 0>
                  translate <0, -0.1, -0.9>
                }

                object {
                  siedzenie_traktora_oparcie
                }
                
        }  // koniec local 'kabina'
        
        #local swiatla_traktora = union {
                box {
                  <-0.2, -0.2, -0.4>
                  <0.2, 0.2, -0.4>
                  pigment {color Yellow}
                }                
        }
        #local maska = union {
           difference {
                   box {
                     <-0.7, -0.6, 1.25>
                     <0.7, 0.6, -1.25>
                     /*<-0.3, -0.8, -0.5>
                     <0.3, 0.4, -2>*/
                     //translate <0, 0.2, 1.25>   // <- przesun wszystko ponizej o tyle
                     pigment {color Red}
                   }
                   // wycinam ten fragment ktory wchodzi do kabiny
                   box {
                    <-0.8, -0.7, 0.8>
                     <0.8, 0.7, 1.27>
                     pigment {color Red}
                   }
           }
           /*object {kabina translate <0, 0.3, 0.4>}
           object {kolo translate <-0.3, -0.5, 1>}
           object {kolo
             scale <0.7, 0.7, 0.7>
             translate <-0.3, -0.8, -1.5>
           }*/
           
           object {
             kabina translate <0, 0.5, 1.65>
           }
           object {
             swiatla_traktora
             translate <-0.4, -0.1, -0.9>
           }
           object {
             swiatla_traktora
             translate <0.4, -0.1, -0.9>
           }
           
           // kola przednie
           object {
             kolo rotate <_obr, 0, 0>
             translate <-0.95, -0.3, 2.25>
           }
           
           object {
             kolo rotate <_obr, 0, 0>
             translate <0.95, -0.3, 2.25>
           }
           
           // kola tylne
           object {kolo
             scale <0.7, 0.7, 0.7>
              rotate <_obr, 0, 0> 
             translate <-0.95, -0.6, -0.25>
           }
           object {kolo
             scale <0.7, 0.7, 0.7>
              rotate <_obr, 0, 0> 
             translate <0.95, -0.6, -0.25>
           }
        }
        
        
        //object {kolo}
        object {maska}

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
  ************************   MACRO DRZEWO   **********************************************
  ****************************************************************************************
*/
#macro drzewo()
        #local korona = sphere {
          <0,0,0>
          0.4
          pigment {color Green}
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
                  translate <0, 0.7, 0>
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











#macro grabie()
        #local zab = cone {
          <0, -0.1, 0>, 0.04
          <0, 0.1, 0>, 0
          pigment {color Grey}
        }
        #local przedluzenieZeba = union {
          cylinder {
            <0,0.2,0>
            <0,-0.2,0>
             0.04
            pigment{color Grey}
          }
          object {
              zab
              translate <0, 0.3, 0>
          }
          
        }
        #local poprzeczka = union {
          box {
            <1, 0.101, 0.08>
            <-1, -0.101, -0.08>
            pigment {color Grey}
          }
          
          #local i=-1;
          #local odleglosc=0.25;
          #while ((i+odleglosc)<=(1+odleglosc))
                object {
                        przedluzenieZeba
                        translate <0+i , 0.2, 0>
                }
                #local i = i+odleglosc;       
          #end
        }
        #local podporka = cylinder {
                <0,0,0.4>, <0,0,-0.4>, 0.06  
                pigment {White_Wood}
        }
        #local kij = union {
          cylinder {
            <0,0,2>
            <0,0,-2>
            0.1
            pigment {White_Wood}
          }
          object {
                podporka         
                translate <0,0,-0.3>
                rotate <0, -120, 0>
                translate <0.1,0,1.6>
          }
          object {
                podporka         
                translate <0,0,0.3>
                rotate <0, -60, 0>
                translate <-0.1,0,1.6>
          }
          object {
                poprzeczka
                translate <0,0,2>
          }
        }
        
        object {kij}
#end





// ###########################################################################

#macro konewka()
        #local lejek = difference {
                cone {
                  <0,0.1,0> , 0.01 
                  <0,-0.1,0> , 0.05
                  pigment {color Green}
                }
                union {
                        cone {
                          <0,0.101,0> , 0.008 
                          <0,-0.09,0> , 0.03
                          pigment {color Green}
                        }
                        box {
                          <0.1, 0.1, 0.>
                          <-0.1, -0.1, -0.1>
                          rotate <45,0,0>
                          translate <0, 0.8, 0>
                        }
                }
        }
        #local srodek = union {
                cylinder {
                  <0,0.1,0>
                  <0,-0.1,0>
                  0.1
                  pigment {color Green}
                }
                torus {
                  0.07, 0.012
                  rotate <90, 90, 0>
                  scale <1, 1.3, 1>
                  translate <0,0.04,-0.16>
                  pigment {color Green}
                }
                object {
                  lejek
                  translate <0,0.08,0>
                  rotate <50, 0,0>
                  translate <0,0,0.05> 
                }
        }
        object {srodek}
#end

   
   
// ###############################################################
#macro siekiera()
        #local ostrze = difference {
                box{
                  <0.005,0.1,0.2>
                  <-0.005,-0.1,-0.2>
                  texture{Polished_Chrome}      
                }
                union {
                        sphere {
                           <0,0,0>, 0.2
                           scale <1,1,1.7> 
                           translate <0,0.26,0.1>
                           pigment {DMFWood1}
                        }
                        sphere {
                           <0,0,0>, 0.2
                           scale <1,1,1.7> 
                           translate <0,-0.26,0.1>
                           pigment {DMFWood1}
                        }                
                }
        }
        #local trzon = union {
                cylinder {
                  <0,0.4,0>
                  <0,-0.4,0>
                  0.05
                  pigment {DMFWood1}
                }
                object {
                  ostrze
                  translate <0,0,-0.2>
                  scale <1.4,1.4,1.4>
                  translate <0,0.3,0>
                }
        }
        object {
          trzon
          scale <5,6,5>
        }
#end









/*
  ****************************************************************************************
  ************************   MACRO BOHATER   *********************************************
  ****************************************************************************************
*/



#macro bohater()
        #local Kolor_skory = Yellow;
        #local Kolor_koszuli = Blue;
        #local Kolor_spodni = Green; 
        #local palec = union {
                cylinder {
                  <0,-0.03, 0>
                  <0, 0.03, 0>                  
                  0.015
                  pigment {color Kolor_skory}
                }
        }
        #local dlon = union {
                // dlon
                sphere {
                  <0,0,0>
                  0.1
                  scale <0.3, 1, 1>
                  pigment {color Kolor_skory}
                }
                // palce w kolejnosci od kciuka do malego
                object {
                  palec
                  translate <0, -0.03, 0>
                  rotate <50, 0, 0>
                  translate <0, 0.01, -0.08>
                }
                object {
                  palec
                  translate <0, -0.08, -0.07>
                }
                object {
                  palec
                  translate <0, -0.1, -0.03>
                }
                object {
                  palec
                  translate <0, -0.09, 0.02>
                }
                object {
                  palec
                  translate <0, -0.07, 0.06>
                }
                object {
                  strzelba()
                  scale <0.1, 0.1, 0.1>
                  rotate <90, 0, 0>
                  rotate <0, 180 , 0>
                  translate <0, -0.5, -0.05>
                }
        }
        #local przedramie = union {
                cylinder {
                  <0, -0.2, 0>
                  <0, 0.2, 0>
                  0.1
                  pigment {color Kolor_koszuli}
                }
                object {
                  dlon
                  translate <0, -0.3, 0>
                }      
        }
        #local ramie = union {
                cylinder {
                  <0, -0.2, 0>
                  <0, 0.2, 0>
                  0.07
                  pigment {color Kolor_koszuli}
                }
                object {
                  przedramie
                  translate <0, -0.2, 0>
                  rotate <120, 0, 0>
                  translate <0, -0.2, 0>
                }      
        }
        #local staw_ramienny = union {
                sphere {
                  <0,0,0>
                  0.13
                  pigment {color Kolor_koszuli}
                }
                object { // prawe ramie
                  ramie
                  //rotate <5*sin(clock*10), 0, 0>
                  rotate <30, 0, 0>
                  translate <0, -0.2, -0.1>
                }
        }
        #local oko = union {
                // galka oczna
                sphere {
                  <0,0,0>
                  0.05
                  pigment {color White}
                }
                // zrenica
                sphere {
                  <0,0,0>
                  0.02
                  translate <0, 0, -0.04>
                  pigment {color Black}
                }
        }
        #local glowa = union {
                sphere {
                  <0,0,0>
                  0.2
                  pigment {color Kolor_skory}
                }
                object {
                  oko
                  translate <-0.07, 0, -0.16>
                }
                object {
                  oko
                  translate <0.07, 0, -0.16>
                }
        }
        #local szyja = union {
                cylinder {
                  <0, -0.08, 0>
                  <0, 0.08, 0>
                  0.05
                  pigment {color Kolor_skory}
                }
                object {
                  glowa
                  translate <0, 0.25, 0>
                }
        }
        #local kaptury = union {
                sphere {
                  <0,0,0>
                  0.2
                  scale <1.5, 1, 0.8>
                  pigment {color Kolor_koszuli}
                }
        }
        #local plecy = union {
                sphere {
                  <0,0,0>
                  0.3
                  scale <1, 0.8, 0.4>
                  pigment {color Kolor_koszuli}
                }
        }
        #local polowa_klaty = union {
                sphere {
                  <0,0,0>
                  0.2
                  scale <1, 0.8, 0.4>
                  //pigment {checker pigment {color <0, 0.72, 0.8>} pigment {White}}
                  pigment {color Kolor_koszuli}
                }
        }
        
        
        #local stopa = union {
                box {
                  <-0.1, -0.05, -0.15>
                  <0.1, 0.05, 0.15>
                  pigment {color Red}         
                }
        }
        #local podudzie = union {
                cylinder {
                  <0, -0.2, 0>
                  <0, 0.2, 0>
                  0.1
                  pigment {color Red}
                }
                object {
                  stopa
                  translate <0, -0.23, -0.08>
                }       
        }
        #local udo = union {
                cylinder {
                  <0, -0.2, 0>
                  <0, 0.2, 0>
                  0.07
                  pigment {color Kolor_spodni}
                }
                object {
                  podudzie
                  translate <0, -0.2, 0>
                  rotate <-110, 0, 0>
                  translate <0, -0.2, 0>
                }      
        }
        #local miednica = union {
                sphere {
                  <0,0,0>
                  0.2
                  scale <0, 0.85, 0.9>
                  pigment {color Kolor_spodni}
                }
                object {
                  udo
                  translate <0, -0.2, 0>
                  rotate <110, 0, -5>
                  translate <-0.1, -0.05, 0>
                }
                object {
                  udo
                  translate <0, -0.2, 0>
                  rotate <110, 0, 5>
                  translate <0.1, -0.05, 0>
                }
        }
        
        
        #local korpus = union {
                cylinder {
                  <0, -0.3, 0>
                  <0, 0.3, 0>
                  0.15
                  pigment {color Kolor_koszuli}
                }
                object {
                  szyja
                  //rotate <0, (((50*clock)<50) ? (50 * clock) : (50)) , 0>
                  translate <0, 0.52, 0>
                }
                object {
                  kaptury
                  translate <0, 0.35, 0.05>
                }
                object {
                  plecy
                  translate <0, 0.23, 0.1>
                }
                
                object {
                  miednica
                  translate <0, -0.25, 0>
                }
                
                object {
                  polowa_klaty
                  translate <-0.07, 0.3, -0.1>
                }
                object {
                  polowa_klaty
                  translate <0.07, 0.3, -0.1>
                }
                object { // prawe ramie
                  staw_ramienny
                  rotate <0, 0, -30>
                  translate <-0.3, 0.35, 0>
                }
                object {
                  staw_ramienny
                  rotate <0, 0, 30>
                  translate <0.3, 0.35, 0>
                }
        }
        
        object {
          korpus
        }
#end

