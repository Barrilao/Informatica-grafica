//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <GL/glut.h>
#include <ctype.h>
#include <math.h>
#include <vector>
#include "objetos_B3.h"


using namespace std;

// tipos
typedef enum{CUBO, PIRAMIDE, OBJETO_PLY, ROTACION, ESFERA, CONO, CILINDRO, PLY_REVOLUCION,ARTICULADO,ARTICULADO_P3} _tipo_objeto;
_tipo_objeto t_objeto=CUBO;
_modo   modo=POINTS;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Size_x,Size_y,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int Window_x=50,Window_y=50,Window_width=450,Window_high=450;
int valor=0;
int flag=0;

// objetos
_cubo cubo(1);
_piramide piramide(0.85,1.3);
_objeto_ply  ply;
_rotacion rotacion;
_esfera esfera(2.0,10,10);
_cono cono(1.0,2.5,14);
_cilindro cilindro(1.0,2,14);
_plyRevolucion ply2;
_tanque tanque;
_ovni ovni;

// _objeto_ply *ply1;


//**************************************************************************
//
//***************************************************************************

void clean_window()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection()
{

glMatrixMode(GL_PROJECTION);
glLoadIdentity();

// formato(x_minimo,x_maximo, y_minimo, y_maximo,plano_delantero, plano_traser)
//  plano_delantero>0  plano_trasero>PlanoDelantero)
glFrustum(-Size_x,Size_x,-Size_y,Size_y,Front_plane,Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación*ply1 de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{

glDisable(GL_LIGHTING);
glLineWidth(2);
glBegin(GL_LINES);
// eje X, color rojo
glColor3f(1,0,0);
glVertex3f(-AXIS_SIZE,0,0);
glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
glColor3f(0,1,0);
glVertex3f(0,-AXIS_SIZE,0);
glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
glColor3f(0,0,1);
glVertex3f(0,0,-AXIS_SIZE);
glVertex3f(0,0,AXIS_SIZE);
glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//****************************2***********************************************

void draw_objects()
{

switch (t_objeto){
				case CUBO: cubo.draw(modo,1.0,0.0,0.0,0.0,1.0,0.0,2);break;
				case PIRAMIDE: piramide.draw(modo,1.0,0.0,0.0,0.0,1.0,0.0,2);break;
        case OBJETO_PLY: ply.draw(modo,1.0,0.6,0.0,0.0,1.0,0.3,2);break;
        case ROTACION: rotacion.draw(modo,1.0,0.0,0.0,0.0,1.0,0.0,6);break;
				case ESFERA: esfera.draw(modo,1.0,0.0,0.0,0.0,1.0,0.0,6);break;
				case CONO: cono.draw(modo,1.0,0.0,0.0,0.0,1.0,0.0,6);break;
				case CILINDRO: cilindro.draw(modo,1.0,0.0,0.0,0.0,1.0,0.0,6);break;
				case PLY_REVOLUCION: ply2.draw(modo,1.0,0.6,0.0,0.0,1.0,0.3,2);break;
				case ARTICULADO: tanque.draw(modo,0.5,0.7,0.2,0.3,0.6,0.3,2);break;
				case ARTICULADO_P3: ovni.draw(modo,0.5,0.7,0.2,0.3,0.6,0.3,2);break;
	}

}


//**************************************************************************
//
//***************************************************************************

void draw(void)
{

clean_window();
change_observer();
draw_axis();
draw_objects();
glutSwapBuffers();
}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1,int Alto1)
{
float Aspect_ratio;

Aspect_ratio=(float) Alto1/(float )Ancho1;
Size_y=Size_x*Aspect_ratio;
change_projection();
glViewport(0,0,Ancho1,Alto1);
glutPostRedisplay();
}


//**********-o*****************************************************************
// Funcion llamada cuando se aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_key(unsigned char Tecla1,int x,int y)
{
switch (toupper(Tecla1)){
	case 'Q':exit(0);
	case '1':modo=POINTS;glutPostRedisplay();break;
	case '2':modo=EDGES;glutPostRedisplay();break;
	case '3':modo=SOLID;glutPostRedisplay();break;
	case '4':modo=SOLID_CHESS;glutPostRedisplay();break;
        case 'P':t_objeto=PIRAMIDE;glutPostRedisplay();break;
        case 'C':t_objeto=CUBO;glutPostRedisplay();break;
        case 'O':t_objeto=OBJETO_PLY;glutPostRedisplay();break;
        case 'R':t_objeto=ROTACION;glutPostRedisplay();break;
				case 'E':t_objeto=ESFERA;glutPostRedisplay();break;
				case 'V':t_objeto=CONO;glutPostRedisplay();break;
				case 'D':t_objeto=CILINDRO;glutPostRedisplay();break;
				case 'I':t_objeto=PLY_REVOLUCION;glutPostRedisplay();break;
				case 'T':t_objeto=ARTICULADO;glutPostRedisplay();break;
				case 'A':t_objeto=ARTICULADO_P3;glutPostRedisplay();break;
				case 'Z':valor=0;glutPostRedisplay();break;
				case 'X':valor=2;glutPostRedisplay();break;
				case 'N':valor-=1;glutPostRedisplay();
								if (valor<=0) valor=0;
								break;
				case 'M':valor+=1;glutPostRedisplay();break;
	}
}

//***************************************************************************
// Funcion l-olamada cuando se aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_key(int Tecla1,int x,int y)
{

switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	case GLUT_KEY_F1:tanque.giro_tubo+=1;
									 if (tanque.giro_tubo>tanque.giro_tubo_max) tanque.giro_tubo=tanque.giro_tubo_max;
									 break;
	case GLUT_KEY_F2:tanque.giro_tubo-=1;
									 if (tanque.giro_tubo<tanque.giro_tubo_min) tanque.giro_tubo=tanque.giro_tubo_min;
									 break;break;
	case GLUT_KEY_F3:tanque.giro_torreta+=5;break;
	case GLUT_KEY_F4:tanque.giro_torreta-=5;break;
	case GLUT_KEY_F5:ovni.giro_pata+=3;
									 if (ovni.giro_pata>ovni.giro_pata_max) ovni.giro_pata=ovni.giro_pata_max;
									 break;
	case GLUT_KEY_F6:ovni.giro_pata-=3;
									 if (ovni.giro_pata<ovni.giro_pata_min) ovni.giro_pata=ovni.giro_pata_min;
									 break;
	case GLUT_KEY_F7:ovni.absorbe_vaca+=5;
									 if (ovni.absorbe_vaca>ovni.vaca_max) ovni.absorbe_vaca=ovni.vaca_max;
									 break;
	case GLUT_KEY_F8:ovni.absorbe_vaca-=5;
									 if (ovni.absorbe_vaca<ovni.vaca_min) ovni.absorbe_vaca=ovni.vaca_min;
									 break;
  case GLUT_KEY_F9:ovni.giro_ovni+=5;break;
  case GLUT_KEY_F10:ovni.giro_ovni-=5;break;
	case GLUT_KEY_F11:ovni.perseguir+=5;break;
	case GLUT_KEY_F12:ovni.perseguir-=5;break;
	}
glutPostRedisplay();
}

void movimiento()
{
	if(valor!=0)
	{
		ovni.giro_ovni+=5;
		ovni.giro_pata += valor-1;
		if(ovni.giro_pata>ovni.giro_pata_max)ovni.giro_pata=ovni.giro_pata_max;
		if (flag==0) ovni.absorbe_vaca -= valor;
		if (flag==0 && ovni.absorbe_vaca<ovni.vaca_min)
		{
			 ovni.absorbe_vaca = ovni.vaca_min;
			 flag=1;
		}
		if (flag==1) ovni.absorbe_vaca += valor;
		if (flag==1 && ovni.absorbe_vaca>ovni.vaca_max)
		{
			 ovni.absorbe_vaca = ovni.vaca_max;
			 flag=0;
		}
		glutPostRedisplay();
	}
}


//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{

// se inicalizan la ventana y los planos de corte
Size_x=0.5;
Size_y=0.5;
Front_plane=1;
Back_plane=1000;

// se incia la posicion del observador, en el eje z
Observer_distance=4*Front_plane;
Observer_angle_x=0;
Observer_angle_y=0;

// se indica cua*ply1l sera el color para limpiar la ventana	(r,v,a,al)
// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
glClearColor(1,1,1,1);

// se habilita el z-bufer
glEnable(GL_DEPTH_TEST);
change_projection();
glViewport(0,0,Window_width,Window_high);



}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************


int main(int argc, char *argv[] )
{




// perfil

vector<_vertex3f> perfil2;
_vertex3f aux;

aux.x=1.0; aux.y=-1.0; aux.z=0.0;
perfil2.push_back(aux);
aux.x=1.0; aux.y=1.0; aux.z=0.0;
perfil2.push_back(aux);
rotacion.parametros(perfil2,6,0,2);



// se llama a la inicialización de glut
glutInit(&argc, argv);

// se indica las caracteristicas que se desean para la visualización con OpenGL
// Las posibilidades son:
// GLUT_SIMPLE -> memoria de imagen simple
// GLUT_DOUBLE -> memoria de imagen doble
// GLUT_INDEX -> memoria de imagen con color indizado
// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
// GLUT_DEPTH -> memoria de profundidad o z-bufer
// GLUT_STENCIL -> memoria de estarcido_rotation Rotation;
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

// posicion de la esquina inferior izquierdad de la ventana
glutInitWindowPosition(Window_x,Window_y);

// tamaño de la ventana (ancho y alto)
glutInitWindowSize(Window_width,Window_high);

// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
// al bucle de eventos)
glutCreateWindow("PRACTICA - 2");

// asignación de la funcion llamada "dibujar" al evento de dibujo
glutDisplayFunc(draw);
// asignación de la funcion llamada "change_window_size" al evento correspondiente
glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "normal_key" al evento correspondiente
glutKeyboardFunc(normal_key);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
glutSpecialFunc(special_key);

glutIdleFunc(movimiento);
// funcion de inicialización
initialize();

// creación del objeto ply
ply.parametros(argv[1]);
ply2.leer_ply_revolucion(argv[2],30);

//ply1 = new _objeto_ply(argv[1]);

// inicio del bucle de eventos
glutMainLoop();
return 0;
}
