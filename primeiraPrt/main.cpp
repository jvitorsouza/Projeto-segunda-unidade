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
    Sculptor escultor_2(30,35,35);

    escultor_2.setColor(0,1,0,1);
    escultor_2.putEllipsoid(13,13,14,14,15,15);
    escultor_2.cutEllipsoid(12,35,12,11,116,10);
    escultor_2.setColor(1,1,1,0.5);
    escultor_2.putSphere(5,17,8,4);
    escultor_2.cutSphere(5,17,8,3);
    escultor_2.putSphere(5,17,16,4);
    escultor_2.cutSphere(5,17,16,3);
    escultor_2.setColor(0,0,0,1);
    escultor_2.putSphere(6,10,8,2);
    escultor_2.putSphere(6,10,16,2);
    escultor_2.cutBox(0,4,0,12,0,25);


    string off_scr("nave");
    escultor_2.writeOFF(off_scr);

    return 0;
}
