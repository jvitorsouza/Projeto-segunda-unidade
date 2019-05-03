#include <iostream>
#include "sculptor.h"

using namespace std;

int main()
{




    //Declarando o objeto para escrever o arquivo .off
    Sculptor escultor_1(3, 3, 3);

    escultor_1.setColor(1, 0, 0, 1);
    escultor_1.putBox(0,1,0,1,0,1);
    escultor_1.cutVoxel(0,0,0);
    escultor_1.setColor(0, 1, 0, 1);
    escultor_1.putVoxel(1,1,1);

    string vect_scr("vect");
    escultor_1.writeVECT(vect_scr);


    //Declarando o objeto para escrever o arquivo .vect
    Sculptor escultor_2(30,40,30);

    escultor_2.setColor(0,1,0,0.7);
    escultor_2.putEllipsoid(12,16,12,12,16,12);
    escultor_2.cutEllipsoid(12,16,12,11,15,11);
    escultor_2.setColor(1,1,1,0.5);
    escultor_2.putSphere(6,16,8,4);
    escultor_2.cutSphere(6,16,8,3);
    escultor_2.putSphere(6,16,16,4);
    escultor_2.cutSphere(6,16,16,3);
    escultor_2.setColor(0,0,0,1);
    escultor_2.putSphere(6,16,8,2);
    escultor_2.putSphere(6,16,16,2);
    escultor_2.cutBox(0,4,0,25,0,25);


    string off_scr("nave");
    escultor2.writeOFF(off_scr);

    return 0;
}
