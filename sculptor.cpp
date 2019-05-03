#include "sculptor.h"
// Construcao da classe que cria a matriz 3D
sculptor::sculptor(int _nx, int _ny, int _nz) //Construtor da classe
{
    nx = _nx;
    ny = _ny;
    nz = _nz;
    v = _v;

    v = new Voxel**[nx];
    if(v == nullptr)
    {
        cout<< "erro de alocacao das linhas da matriz"<<endl;
        exit(0);
    }

    v[0] = new Voxel *[nx*ny];
        if(v[0] == nullptr)
    {
        cout<< "erro de alocacao das colunas da matriz"<<endl;
        exit(0);
    }
    v[0][0] = new Voxel [nx*ny*nz];
        if(v[0][0] == nullptr)
    {
        cout<< "erro de alocacao das linhas da matriz"<<endl;
        exit(0);
    }
        //colunas
    for (int i = 1; i<nx; i++)
    {
        v[i] = v[i-1] + ny;
    }
        //planos
    for (int i = 1; i<ny*nz; i++)
    {
        v[0][i] = v[0][i-1] + nz;
    }

    for (int i=0; i<nx; i++)
    {
        for (int j=0; i<ny; j++)
        {
            for (int k=0; k<nz; k++)
            {
                v[i][j][k].isOn = false;
                v[i][j][k].r = 255; // duvida
                v[i][j][k].g = 255; //duvida
                v[i][j][k].b = 255; //duvida

            }
        }
    }

}

sculptor::~sculptor() Destrutor da classe
{
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

Voxel& sculptor::operator ()(int i, int j, int k)
{
    if (i >=0 && j>=0 && k>0 && i<nx && k < nz)
    {
        return v[i][j][z]; // retornar os enderecoes dos voxel
    }
    else exit(0);
}

void sculptor::print()
{
    for (int i=0; i< nx; i++){
        for (int j=0; j<ny; j++){
            for (int k=0; k<nz; k++){

                cout <<v[i][j][k].isOn<<" ";
            }
            cout <<endl;
        }
        cout <<endl;
        cout <<endl;
    }
}

void sculptor::setColor(float red, float green, float blue, float alpha) //Define a cor atual de desenho.
{
    r = red;
    g = green;
    b = blue;
    a = alpha;
}

void sculptor::putVoxel(int x, int y, int z) //Ativa o voxel na posição (x,y,z) (fazendo isOn = true)
                                               //e atribui ao mesmo a cor atual de desenho
{
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void sculptor::cutVoxel(int x, int y, int z) //Desativa o voxel na posição (x,y,z) (fazendo isOn = false)
{
    v[x][y][z].isOn = false;
}

void sculptor::putBox( int x0, int x1, int y0, int y1, int z0, int z1) //Ativa todos os voxels no intervalo
                                                                       //x∈[x0,x1], y∈[y0,y1], z∈[z0,z1]
                                                                       //e atribui aos mesmos a cor atual de desenho
{
    for( int i = 0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if (i>=x0 && i<=x1 && j>=y0 && j<=y1 && k>=z0 && k<=z1){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

void sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) //Desativa todos os voxels no intervalo
                                                                      //x∈[x0,x1], y∈[y0,y1], z∈[z0,z1]
                                                                      //e atribui aos mesmos a cor atual de desenho
{
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if(i>=x0 && i<=x1 && j>=y0 && j<=y1 && k>=z0 && k<=z1){
                    v[i][j][k].isOn = false;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}
void sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) //Ativa todos os voxels que satisfazem
                                                                           //à equação da esfera e atribui aos mesmos a cor atual de desenho
{
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if(
                        ((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter)) <= radius*radius
                        ){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

void sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) // Desativa todos os voxels que satisfazem à equação da esfera
{
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if( ((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter)) <= radius*radius ){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

void sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) //Ativa todos os voxels que satisfazem à equação do elipsóide
                                                                                           //e atribui aos mesmos a cor atual de desenho
{
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if( (((i - xcenter)*(i - xcenter))/(float)(rx*rx) + ((j - ycenter)*(j - ycenter))/(float)(ry*ry) + ((k - zcenter)*(k - zcenter))/(float)(rz*rz)) <= 1 ){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

void sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) //Desativa todos os voxels que satisfazem à equação do elipsóide
{
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if( (((i - xcenter)*(i - xcenter))/(float)(rx*rx) + ((j - ycenter)*(j - ycenter))/(float)(ry*ry) + ((k - zcenter)*(k - zcenter))/(float)(rz*rz)) <= 1 ){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

void sculptor::writeOFF(string filename)
{
    ofstream fout;


    fout.open("./"+filename+".off");
    if(fout.is_open() == false)
    {
        cout << "arquivo nao foi aberto\n";
        exit(1);
    }

    fout<<"OFF"<<endl;

    int nvoxels = 0;
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if(v[i][j][k].isOn){
                    nvoxels = nvoxels+1;
                }
            }
        }
    }
    fout<<nvoxels*8<<" "<<nvoxels*6<<" 0"<<endl;



void sculptor::writeVECT(string filename)
{
    ofstream fout;

    fout.open("./"+filename+".vect");
    if(fout.is_open() == false)
    {
        cout << "arquivo nao foi aberto\n";
        exit(1);
    }

    fout<<"VECT"<<endl;

    int nvoxels = 0;
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if(v[i][j][k].isOn){
                    nvoxels = nvoxels+1;
                }
            }
        }
    }
    fout<<nvoxels<<" "<<nvoxels<<" "<<nvoxels<<endl;

    for(int i = 1; i<nvoxels; i++){
        fout<<"1 ";
    }
    fout<<"1"<<endl;

    for(int i = 1; i<nvoxels; i++){
        fout<<"1 ";
    }
    fout<<"1"<<endl;

    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if(v[i][j][k].isOn){
                    fout<<i<<" "<<j<<" "<<k<<endl;
                }
            }
        }
    }

    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if(v[i][j][k].isOn){
                    fout<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                }
            }
        }
    }

}
