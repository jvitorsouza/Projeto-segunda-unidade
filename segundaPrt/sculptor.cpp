#include "sculptor.h" 

Sculptor::Sculptor()
{

}

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx; ny = _ny; nz = _nz;

    if(nx < 0 or ny < 0 or nz < 0)
    {
        nx = 0; ny = 0; nz = 0;
    }


    vx = new Voxel**[nx];

    if(vx == nullptr)
    {
        cout<<"FLAG: Erro de alocacao I"<<endl;
        exit(0);
    }


    vx[0] = new Voxel*[nx*ny];

    if(vx[0] == nullptr)
    {
        cout<<"FLAG: Erro de alocacao II"<<endl;
        exit(0);
    }


    vx[0][0] = new Voxel[nx*ny*nz];

    if(vx[0][0] == nullptr)
    {
        cout<<"FLAG: Erro de alocacao III"<<endl;
        exit(0);
    }

    for(int i = 1; i<nx; i++){
        vx[i] = vx[i-1] + ny;
    }

        for(int i = 1; i<nx*ny; i++){
        vx[0][i] = vx[0][i-1] + nz;
    }

        for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                vx[i][j][k].isOn = false;
            }
        }
    }
}
void Sculptor::setColor(float red, float green, float blue, float alpha)
{
    r = red;
    g = green;
    b = blue;
    a = alpha;
}
void Sculptor::putVoxel(int x, int y, int z)
{
    if(x>=0 && x<nx &&
       y>=0 && y<ny &&
       z>=0 && z<nz){
        vx[x][y][z].isOn = true;
        vx[x][y][z].r = r;
        vx[x][y][z].g = g;
        vx[x][y][z].b = b;
        vx[x][y][z].a = a;
    }
}
void Sculptor::cutVoxel(int x, int y, int z)
{
    if(x>=0 && x<nx &&
       y>=0 && y<ny &&
       z>=0 && z<nz){
        vx[x][y][z].isOn = false;
    }
}

Sculptor::~Sculptor()
{
    if(nx < 0 or ny < 0 or nz < 0)
    {
        return;
    }

    delete [] vx[0][0];
    delete [] vx[0];
    delete [] vx;
}

void Sculptor::writeOFF(string filename)
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
                if(vx[i][j][k].isOn){
                    nvoxels = nvoxels+1;
                }
            }
        }
    }
    fout<<nvoxels*8<<" "<<nvoxels*6<<" 0"<<endl;

    float vRadius=0.5f;
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if(vx[i][j][k].isOn){
                    fout<<(float)i-vRadius<<" "<<(float)j+vRadius<<" "<<(float)k-vRadius<<endl;
                    fout<<(float)i-vRadius<<" "<<(float)j-vRadius<<" "<<(float)k-vRadius<<endl;
                    fout<<(float)i+vRadius<<" "<<(float)j-vRadius<<" "<<(float)k-vRadius<<endl;
                    fout<<(float)i+vRadius<<" "<<(float)j+vRadius<<" "<<(float)k-vRadius<<endl;
                    fout<<(float)i-vRadius<<" "<<(float)j+vRadius<<" "<<(float)k+vRadius<<endl;
                    fout<<(float)i-vRadius<<" "<<(float)j-vRadius<<" "<<(float)k+vRadius<<endl;
                    fout<<(float)i+vRadius<<" "<<(float)j-vRadius<<" "<<(float)k+vRadius<<endl;
                    fout<<(float)i+vRadius<<" "<<(float)j+vRadius<<" "<<(float)k+vRadius<<endl;
                }
            }
        }
    }

    fout << std::setprecision(1) << fixed;
    int vacc = 0;
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if(vx[i][j][k].isOn){
                    fout<<"4 "<<vacc+0<<" "<<vacc+3<<" "<<vacc+2<<" "<<vacc+1<<" "<<vx[i][j][k].r<<" "<<vx[i][j][k].g<<" "<<vx[i][j][k].b<<" "<<vx[i][j][k].a<<endl;
                    fout<<"4 "<<vacc+4<<" "<<vacc+5<<" "<<vacc+6<<" "<<vacc+7<<" "<<vx[i][j][k].r<<" "<<vx[i][j][k].g<<" "<<vx[i][j][k].b<<" "<<vx[i][j][k].a<<endl;
                    fout<<"4 "<<vacc+0<<" "<<vacc+1<<" "<<vacc+5<<" "<<vacc+4<<" "<<vx[i][j][k].r<<" "<<vx[i][j][k].g<<" "<<vx[i][j][k].b<<" "<<vx[i][j][k].a<<endl;
                    fout<<"4 "<<vacc+0<<" "<<vacc+4<<" "<<vacc+7<<" "<<vacc+3<<" "<<vx[i][j][k].r<<" "<<vx[i][j][k].g<<" "<<vx[i][j][k].b<<" "<<vx[i][j][k].a<<endl;
                    fout<<"4 "<<vacc+3<<" "<<vacc+7<<" "<<vacc+6<<" "<<vacc+2<<" "<<vx[i][j][k].r<<" "<<vx[i][j][k].g<<" "<<vx[i][j][k].b<<" "<<vx[i][j][k].a<<endl;
                    fout<<"4 "<<vacc+1<<" "<<vacc+2<<" "<<vacc+6<<" "<<vacc+5<<" "<<vx[i][j][k].r<<" "<<vx[i][j][k].g<<" "<<vx[i][j][k].b<<" "<<vx[i][j][k].a<<endl;
                    vacc = vacc+8;
                }
            }
        }
    }
}

void Sculptor::writeVECT(string filename)
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
                if(vx[i][j][k].isOn){
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
                if(vx[i][j][k].isOn){
                    fout<<i<<" "<<j<<" "<<k<<endl;
                }
            }
        }
    }

    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if(vx[i][j][k].isOn){
                    fout<<vx[i][j][k].r<<" "<<vx[i][j][k].g<<" "<<vx[i][j][k].b<<" "<<vx[i][j][k].a<<endl;
                }
            }
        }
    }

}
