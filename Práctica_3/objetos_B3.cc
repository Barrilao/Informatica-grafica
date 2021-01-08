//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "objetos_B3.h"
#include "file_ply_stl.hpp"


//*************************************************************************
// _puntos3D
//*************************************************************************

_puntos3D::_puntos3D()
{
}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
int i;
glPointSize(grosor);
glColor3f(r,g,b);
glBegin(GL_POINTS);
for (i=0;i<vertices.size();i++){
	glVertex3fv((GLfloat *) &vertices[i]);
	}
glEnd();
}


//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}


//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}

//*************************************************************************
// dibujar en modo sólido
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{

	int i;
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glColor3f(r,g,b);
	glBegin(GL_TRIANGLES);
	for (i=0;i<caras.size();i++){
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
		}
	glEnd();

}

//*************************************************************************
// dibujar en modo sólido con apariencia de ajedrez
//*************************************************************************

void _triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2)
{
	int i;
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glBegin(GL_TRIANGLES);
	for (i=0;i<caras.size();i++){
		if(i%2==0) glColor3f(r1,g1,b1);
		else glColor3f(r2,g2,b2);
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
		}
	glEnd();
}

//*************************************************************************
// dibujar con distintos modos
//*************************************************************************

void _triangulos3D::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
switch (modo){
	case POINTS:draw_puntos(r1, g1, b1, grosor);break;
	case EDGES:draw_aristas(r1, g1, b1, grosor);break;
	case SOLID_CHESS:draw_solido_ajedrez(r1, g1, b1, r2, g2, b2);break;
	case SOLID:draw_solido(r1, g1, b1);break;
	}
}

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{

	//vertices
	vertices.resize(8);
	vertices[0].x=-tam;vertices[0].y=-tam;vertices[0].z=tam;
	vertices[1].x=tam;vertices[1].y=-tam;vertices[1].z=tam;
	vertices[2].x=tam;vertices[2].y=tam;vertices[2].z=tam;
	vertices[3].x=-tam;vertices[3].y=tam;vertices[3].z=tam;
	vertices[4].x=-tam;vertices[4].y=-tam;vertices[4].z=-tam;
	vertices[5].x=tam;vertices[5].y=-tam;vertices[5].z=-tam;
	vertices[6].x=tam;vertices[6].y=tam;vertices[6].z=-tam;
	vertices[7].x=-tam;vertices[7].y=tam;vertices[7].z=-tam;

	// triangulos
	caras.resize(12);
	caras[0]._0=0;caras[0]._1=1;caras[0]._2=4; // Cara 1
	caras[1]._0=1;caras[1]._1=5;caras[1]._2=4; // Cara 2

	caras[2]._0=1;caras[2]._1=2;caras[2]._2=5; // Cara 3
	caras[3]._0=2;caras[3]._1=6;caras[3]._2=5; // Cara 4

	caras[4]._0=2;caras[4]._1=3;caras[4]._2=6; // Cara 5
	caras[5]._0=3;caras[5]._1=7;caras[5]._2=6; // Cara 6

	caras[6]._0=3;caras[6]._1=0;caras[6]._2=7; // Cara 7
	caras[7]._0=0;caras[7]._1=4;caras[7]._2=7; // Cara 8

	caras[8]._0=4;caras[8]._1=5;caras[8]._2=6; // Cara 9
	caras[9]._0=4;caras[9]._1=6;caras[9]._2=7; // Cara 10

	caras[10]._0=3;caras[10]._1=1;caras[10]._2=0; // Cara 11
	caras[11]._0=3;caras[11]._1=2;caras[11]._2=1; // Cara 12
}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{

//vertices
vertices.resize(5);
vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
vertices[4].x=0;vertices[4].y=al;vertices[4].z=0;

caras.resize(6);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
caras[4]._0=3;caras[4]._1=1;caras[4]._2=0;
caras[5]._0=3;caras[5]._1=2;caras[5]._2=1;
}

//*************************************************************************
// clase cilindro
//*************************************************************************

//*************************************************************************
// clase cono
//*************************************************************************

//*************************************************************************
// clase esfera
//*************************************************************************


//*************************************************************************
// clase objeto ply
//*************************************************************************

// HACER
_objeto_ply::_objeto_ply()
{
   // leer lista de coordenadas de vértices y lista de indices de vértices

}


// Hecho
int _objeto_ply::parametros(char *archivo)
{
int n_ver,n_car, i;

vector<float> ver_ply ;
vector<int>   car_ply ;

_file_ply::read(archivo, ver_ply, car_ply );

n_ver=ver_ply.size()/3; //x1, y1, z1, x2, y2, z3.....
n_car=car_ply.size()/3;

printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

vertices.resize(n_ver);
caras.resize(n_car);

// Faltaba esto

for(i = 0; i < vertices.size(); i++){
	// Por estar ply en forma de matriz
		vertices[i].x = ver_ply[3*i];
		vertices[i].y = ver_ply[3*i+1];
		vertices[i].z = ver_ply[3*i+2];
}

for(i = 0; i < caras.size(); i++){
	// Por estar ply en forma de matriz
		caras[i].x = car_ply[3*i];
		caras[i].y = car_ply[3*i+1];
		caras[i].z = car_ply[3*i+2];
}

//

return(0);
}

// HACER
_plyRevolucion::_plyRevolucion()
{


}


// Hecho
void _plyRevolucion::leer_ply_revolucion(char *archivo, int num1)
{
	unsigned int i;

	vector<float> ver_ply ;
	vector<int>   car_ply ;
	vector<_vertex3f> perfil;

	_file_ply::read(archivo, ver_ply, car_ply);

	int n_ver=ver_ply.size()/3;
	perfil.resize(n_ver);


	// Faltaba esto

	for(i = 0; i < perfil.size(); i++){
		// Por estar ply en forma de matriz
			perfil[i].x = ver_ply[3*i];
			perfil[i].y = ver_ply[3*i+1];
			perfil[i].z = ver_ply[3*i+2];
	}

	parametros(perfil,num1,0);

}

//************************************************************************
// objeto por revolucion
//************************************************************************

// HACER
_rotacion::_rotacion()
{

}


void _rotacion::parametros(vector<_vertex3f> perfil, int num, int tipo, int parte)
{
int i,j;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;
float radio;

int l = 0;
if(parte>1)l = 1;

if (tipo==2)
	radio=sqrt(perfil[0].x*perfil[0].x+perfil[0].y*perfil[0].y);

// tratamiento de los vértice

num_aux=perfil.size();

if (tipo==1)	num_aux=1;

vertices.resize(num_aux*num+2); //+2 por las tapas
for (j=0;j<num;j++)
  {for (i=0;i<num_aux;i++)
     {
      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*(num-l)*parte))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*(num-l)*parte));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*(num-l)*parte))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*(num-l)*parte));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
     }
  }

// tratamiento de las caras

caras.resize((num_aux-1)*2*num+2*num);

// Cilindro revolucion

int c = 0;

if(tipo==0 || tipo==2)
	{for(j = 0; j<num-l; j++){
		for(i = 0; i < num_aux-1;i++){
			caras[c]._0=j*num_aux+i;
			caras[c]._1=j*num_aux+1+i;
			caras[c]._2=((j+1)%num)*num_aux+1+i;
			c+=1;
			caras[c]._0=((j+1)%num)*num_aux+1+i;
			caras[c]._1=((j+1)%num)*num_aux+i;
			caras[c]._2=j*num_aux+i;
			c+=1;
		}
	}
}


 // tapa inferior
if (fabs(perfil[0].x)>0.0)
  {
		vertices[num_aux*num].x = 0.0;
		if(tipo==0) vertices[num_aux*num].y = perfil[0].y;	//revolucion cualquiera
		if(tipo==1) vertices[num_aux*num].y = 0.0;   //cono
		if(tipo==2) vertices[num_aux*num].y = -radio;	//esfera
		vertices[num_aux*num].z = 0.0;

		for(j = 0; j<num-l; j++){
			caras[c]._0=num_aux*num;
			caras[c]._1=j*num_aux;
			caras[c]._2=((j+1)%num)*num_aux;
			c+=1;
		}
	}

 // tapa superior
 if (fabs(perfil[num_aux-1].x)>0.0)
  {
		vertices[num_aux*num+1].x = 0.0;
		if(tipo==0) vertices[num_aux*num+1].y = perfil[num_aux-1].y; //revolucion cualquiera
		if(tipo==1) vertices[num_aux*num+1].y = perfil[1].y;   //cono
		if(tipo==2) vertices[num_aux*num+1].y = radio;	//esfera
		vertices[num_aux*num+1].z = 0.0;

		for(j = 0; j<num-l; j++){
			caras[c]._0=num_aux*num+1;
			caras[c]._1=j*num_aux+num_aux-1;
			caras[c]._2=((j+1)%num)*num_aux+num_aux-1;
			c+=1;
		}
  }
}

_esfera::_esfera(float radio, int n, int m)
{
	vector<_vertex3f> perfil1;
	_vertex3f aux;
	int i;

	for(i=1;i<n;i++){
		aux.x=radio*cos(M_PI*i/n-M_PI/2.0);
		aux.y=radio*sin(M_PI*i/n-M_PI/2.0);
		aux.z=0.0;
		perfil1.push_back(aux);
	}
	parametros(perfil1,m,2);

}

_cilindro::_cilindro(float radio, float altura, int n)
{
	vector<_vertex3f> perfil1;
	_vertex3f aux;

	aux.x=radio;
	aux.y=-altura/2.0;
	aux.z=0.0;
	perfil1.push_back(aux);

	aux.x=radio;
	aux.y=altura/2.0;
	aux.z=0.0;
	perfil1.push_back(aux);

	parametros(perfil1,n,0);

}

_cono::_cono(float radio, float altura, int n)
{
	vector<_vertex3f> perfil1;
	_vertex3f aux;

	aux.x=radio;
	aux.y=0.0;
	aux.z=0.0;
	perfil1.push_back(aux);

	aux.x=0;
	aux.y=altura;
	aux.z=0.0;
	perfil1.push_back(aux);

	parametros(perfil1,n,1);

}


//************************************************************************
// objeto articulado: tanque
//************************************************************************

_chasis::_chasis()
{
// perfil para un cilindro
vector<_vertex3f> perfil;
_vertex3f aux;
aux.x=0.107;aux.y=-0.5;aux.z=0.0;
perfil.push_back(aux);
aux.x=0.107;aux.y=0.5;aux.z=0.0;
perfil.push_back(aux);
rodamiento.parametros(perfil,12,0);
altura=0.22;
};

void _chasis::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
glPushMatrix();
glScalef(1.0,0.22,0.95);
base.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glRotatef(90.0,1,0,0);
rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.25,0.0,0.0);
glRotatef(90.0,1,0,0);
rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.5,0.0,0.0);
glRotatef(90.0,1,0,0);
rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(0.25,0.0,0.0);
glRotatef(90.0,1,0,0);
rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(0.5,0.0,0.0);
glRotatef(90.0,1,0,0);
rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();
}

//************************************************************************

_torreta::_torreta()
{
altura=0.18;
anchura=0.65;
};

void _torreta::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
glPushMatrix();
glScalef(0.65,0.18,0.6);
base.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.325,0,0);
glRotatef(90.0,0,0,1);
glScalef(0.18,0.16,0.6);
parte_trasera.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();
}

//************************************************************************

_tubo::_tubo()
{
// perfil para un cilindro
vector<_vertex3f> perfil;
_vertex3f aux;
aux.x=0.04;aux.y=-0.4;aux.z=0.0;
perfil.push_back(aux);
aux.x=0.04;aux.y=0.4;aux.z=0.0;
perfil.push_back(aux);
tubo_abierto.parametros(perfil,12,0);
};

void _tubo::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{

glPushMatrix();
glTranslatef(0.4,0,0);
glRotatef(90.0,0,0,1);
tubo_abierto.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();
}


//************************************************************************

_tanque::_tanque()
{
giro_tubo=2.0;
giro_torreta=0.0;
giro_tubo_min=-9;
giro_tubo_max=20;
};

void _tanque::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
glPushMatrix();
	chasis.draw(modo, r1, g1, b1, r2, g2, b2, grosor);

	glRotatef(giro_torreta,0,1,0);
	glPushMatrix();
		glTranslatef(0.0,(chasis.altura+torreta.altura)/2.0,0.0);
		torreta.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(torreta.anchura/2.0,(chasis.altura+torreta.altura)/2.0,0.0);
		glRotatef(giro_tubo,0,0,1);
		tubo.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();
glPopMatrix();

};
/////////////////////////////////////////

_pata::_pata(){
	char name[]="./ply/pata\0";
	pata.parametros(name);
}

void 	_pata::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
	glPushMatrix();
	glTranslatef(19,-12.8,-15);
	glRotatef(180,1,0,0);
	pata.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();
}

_base::_base(){
	char name[]="./ply/base\0";
	base.parametros(name);
}

void 	_base::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
	glPushMatrix();
	glTranslatef(0,0,-3.5);
	glRotatef(180,1,0,0);
	base.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();
}

_superior::_superior(){
	char name[]="./ply/superior\0";
	superior.parametros(name);
}

void 	_superior::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
	glPushMatrix();
	glTranslatef(0,0,-3.5);
	glScalef(0.75,1,0.75);
	superior.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();
}

_luz::_luz(){
	char name[]="./ply/luz\0";
	luz.parametros(name);
}

void 	_luz::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
	glPushMatrix();
	glScalef(0.5,1,0.5);
	luz.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();
}

_vaca::_vaca(){
	char name[]="./ply/vaca\0";
	vaca.parametros(name);
}

void 	_vaca::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
	glPushMatrix();
	glScalef(0.2,0.2,0.2);
	glRotatef(180,1,0,0);
	vaca.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();
}

_ovni::_ovni(){
	giro_pata=0.0;
	giro_ovni=0.0;
	perseguir=0.0;
	absorbe_vaca=0.0;
	giro_pata_min=-21;
	giro_pata_max=39;
	vaca_min=0;
	vaca_max=55;
}

void _ovni::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
	glPushMatrix();
			glTranslatef(0,0,perseguir);
		glPushMatrix();
			glTranslatef(0,absorbe_vaca,0);
			glTranslatef(0,-50,0);
			glRotatef(absorbe_vaca,1,1,1);
			vaca.draw(modo,r1,g1,b1,r2,g2,b2,grosor);
		glPopMatrix();
		glPushMatrix();
			glRotatef(-giro_ovni,0,1,0);
			luz.draw(modo,r1,g1,b1,r2,g2,b2,grosor);
		glPopMatrix();
		glPushMatrix();
			glRotatef(giro_ovni,0,1,0);
			glPushMatrix();
				glTranslatef(0,8,0);
				superior.draw(modo,r1,g1,b1,r2,g2,b2,grosor);
			glPopMatrix();
			glPushMatrix();
					base.draw(modo,r1,g1,b1,r2,g2,b2,grosor);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0,0,-19);
				glRotatef(-giro_pata,1,0,0);
				glRotatef(-90,0,1,0);
				pata.draw(modo,r1,g1,b1,r2,g2,b2,grosor);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0,0,19);
				glRotatef(giro_pata,1,0,0);
				glRotatef(90,0,1,0);
				pata.draw(modo,r1,g1,b1,r2,g2,b2,grosor);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(19,0,0);
				glRotatef(-giro_pata,0,0,1);
				glRotatef(180,0,1,0);
				pata.draw(modo,r1,g1,b1,r2,g2,b2,grosor);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-19,0,0);
				glRotatef(giro_pata,0,0,1);
				pata.draw(modo,r1,g1,b1,r2,g2,b2,grosor);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

}
