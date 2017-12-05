/*
    main.cpp

    Copyright (C) 2013 by Don Cross  -  http://cosinekitty.com/raytrace

    This software is provided 'as-is', without any express or implied
    warranty. In no event will the author be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
       claim that you wrote the original software. If you use this software
       in a product, an acknowledgment in the product documentation would be
       appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
       misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
       distribution.

    -------------------------------------------------------------------------

    Main source file for my demo 3D ray-tracing image maker.
*/
#include <windows.h>
#include <iostream>
#include "algebra.h"
#include "block.h"
#include "chessboard.h"
#include "planet.h"
#include "polyhedra.h"
void SphereTest();

//Scene scene(Color(0.37, 0.45, 0.37, 7.0e-6));

void AddSceneMirrors(Imager::Scene& scene)
{
    using namespace Imager;
    Optics optics;
    optics.SetMatteGlossBalance(1.0, Color(1.0, 1.0, 1.0), Color(1.0, 1.0, 1.0));

    ChessBoard * mirror[1];
    for (int i=0; i < 1; ++i)
    {
        mirror[i] = new ChessBoard(0.0,50.0,50.0, 0.50,Color(0.0,0.0,0.0),Color(0.0,0.0,0.0),Color(0.0,0.0,0.0));
        mirror[i]->SetUniformOptics(optics);
    }

    // Rotate/translate the three mirrors differently.
    // Use the common value 's' that tells how far
    // The bottom mirror just moves down (in the -y direction)
    mirror[0]-> Move(0.0, -8.0, -250.0);
    mirror[0]->RotateX(8.0);
    mirror[0]->SetTag("bottom mirror");

    // The upper left mirror moves up and left
    // and rotates +60 degrees around z axis.
//    mirror[1]-> Move(0.0, 12.0, -100.0);
//    mirror[1]->RotateX(-90.0);
//    mirror[1]->SetTag("left mirror");


    scene.AddSolidObject(mirror[0]);
}


void Escena()
{
        using namespace Imager;
    //Usamos un objeto "Escena" para incorporar todo el modelo
    Scene scene(Color(0.0, 0.0, 0.0));
    const Color cafe =  Color(0.35,0.23,0.12);
    const Color verde = Color(0.19,0.69,0.23);
    const Color colorMesa = Color(1, 1, 1);
    const Color rojo = Color(1.0, 0.0, 0.0);
    const Color azul = Color(0.0,0.0,1.0);
    const Color morado = Color(0.43,0.11,0.74); //rgb(109, 28, 190)
    const Color cyan = Color(0.43,0.81,0.82); //rgb(0,206,209)
    const Color dorado = Color(1.0,0.84,0.0); //rgb(255,215,0)

     Vector centroTronco1 = Vector(0.0, -5.0, -100.0);
     Vector centroTronco2 = Vector(-15.0, -5.0, -150.0);
     Vector centroTronco3 = Vector(15.0, -5.0, -150.0);
     Vector centroTronco4 = Vector(-29.0, -5.0, -200.0);
     Vector centroTronco5 = Vector(29.0, -5.0, -200.0);

  /**<  Creación de los Cilindros / Troncos, de izquierda a derecha */
    //196/255, 103/255, 10/255

    Cylinder* cylinder4 = new Cylinder(2.0, 4.0);
    cylinder4->SetFullMatte(cafe);
    cylinder4->Move(centroTronco4);
    cylinder4->RotateX(-90.0);
    scene.AddSolidObject(cylinder4);

    Cylinder* cylinder2 = new Cylinder(2.0, 4.0);
    cylinder2->SetFullMatte(cafe);
    cylinder2->Move(centroTronco2);
    cylinder2->RotateX(-90.0);
    scene.AddSolidObject(cylinder2);
//
    Cylinder* cylinder1 = new Cylinder(2.0, 4.0);
    cylinder1->SetFullMatte(cafe);
    cylinder1->Move(centroTronco1);
    cylinder1->RotateX(-90.0);
    scene.AddSolidObject(cylinder1);

    Cylinder* cylinder3 = new Cylinder(2.0, 4.0);
    cylinder3->SetFullMatte(cafe);
    cylinder3->Move(centroTronco3);
    cylinder3->RotateX(-90.0);
    scene.AddSolidObject(cylinder3);

    Cylinder* cylinder5 = new Cylinder(2.0, 4.0);
    cylinder5->SetFullMatte(cafe);
    cylinder5->Move(centroTronco5);
    cylinder5->RotateX(-90.0);
    scene.AddSolidObject(cylinder5);

    /**< Creación de los conos, desde el centro hacia los lados. */

    Cone* cone1 = new Cone(3.5, 12.0);
    cone1->SetFullMatte(verde);
    cone1->Move(centroTronco1.x,centroTronco1.y + 7.6, centroTronco1.z + 3.6);
    cone1->RotateX(-90.0);
    scene.AddSolidObject(cone1);

    Cone* cone2 = new Cone(3.5, 12.0);
    cone2->SetFullMatte(verde);
    cone2->Move(centroTronco2.x,centroTronco2.y + 7.6, centroTronco2.z + 3.6);
    cone2->RotateX(-90.0);
    scene.AddSolidObject(cone2);

    Cone* cone3 = new Cone(3.5, 12.0);
    cone3->SetFullMatte(verde);
    cone3->Move(centroTronco3.x,centroTronco3.y + 7.6, centroTronco3.z + 3.6);
    cone3->RotateX(-90.0);
    scene.AddSolidObject(cone3);

    Cone* cone4 = new Cone(3.5, 12.0);
    cone4->SetFullMatte(verde);
    cone4->Move(centroTronco4.x,centroTronco4.y + 7.6, centroTronco4.z + 3.6);
    cone4->RotateX(-90.0);
    scene.AddSolidObject(cone4);

    Cone* cone5 = new Cone(3.5, 12.0);
    cone5->SetFullMatte(verde);
    cone5->Move(centroTronco5.x,centroTronco5.y + 7.6, centroTronco5.z + 3.6);
    cone5->RotateX(-90.0);
    scene.AddSolidObject(cone5);


    /**< Creación de las esferas para cada cono, desde el centro hacia los lados. */

    /**< Árbol 1. */
    Sphere* esfera1 = new Sphere(Vector(centroTronco1.x + 0.0, 4.0, centroTronco1.z + 5), 0.5);
    esfera1->SetFullMatte(rojo);
    scene.AddSolidObject(esfera1);

    Sphere* esfera2 = new Sphere(Vector(centroTronco1.x + 1.0, 2.5, centroTronco1.z + 5.5), 0.5);
    esfera2->SetFullMatte(azul);
    scene.AddSolidObject(esfera2);

    Sphere* esfera3 = new Sphere(Vector(centroTronco1.x + -1.0, 1.0, centroTronco1.z + 6), 0.5);
    esfera3->SetFullMatte(morado);
    scene.AddSolidObject(esfera3);

    Sphere* esfera4 = new Sphere(Vector(centroTronco1.x + 2.0, -0.5, centroTronco1.z + 6), 0.5);
    esfera4->SetFullMatte(cyan);
    scene.AddSolidObject(esfera4);

    Sphere* esfera5 = new Sphere(Vector(centroTronco1.x + -2.0, -2.0, centroTronco1.z + 6.5), 0.5);
    esfera5->SetFullMatte(dorado);
    scene.AddSolidObject(esfera5);

    /**< Árbol 2. */
    Sphere* esfera6 = new Sphere(Vector(centroTronco2.x + 0.0, 4.0, centroTronco2.z + 5), 0.5);
    esfera6->SetFullMatte(rojo);
    scene.AddSolidObject(esfera6);

    Sphere* esfera7 = new Sphere(Vector(centroTronco2.x + 1.0, 2.5, centroTronco2.z + 5.5), 0.5);
    esfera7->SetFullMatte(azul);
    scene.AddSolidObject(esfera7);

    Sphere* esfera8 = new Sphere(Vector(centroTronco2.x + -1.0, 1.0, centroTronco2.z + 6), 0.5);
    esfera8->SetFullMatte(morado);
    scene.AddSolidObject(esfera8);

    Sphere* esfera9 = new Sphere(Vector(centroTronco2.x + 2.0, -0.5, centroTronco2.z + 6), 0.5);
    esfera9->SetFullMatte(cyan);
    scene.AddSolidObject(esfera9);

    Sphere* esfera10 = new Sphere(Vector(centroTronco2.x + -2.0, -2.0, centroTronco2.z + 6.5), 0.5);
    esfera10->SetFullMatte(dorado);
    scene.AddSolidObject(esfera10);

    /**< Árbol 3. */
    Sphere* esfera11 = new Sphere(Vector(centroTronco3.x + 0.0, 4.0, centroTronco3.z + 5), 0.5);
    esfera11->SetFullMatte(rojo);
    scene.AddSolidObject(esfera11);

    Sphere* esfera12 = new Sphere(Vector(centroTronco3.x + 1.0, 2.5, centroTronco3.z + 5.5), 0.5);
    esfera12->SetFullMatte(azul);
    scene.AddSolidObject(esfera12);

    Sphere* esfera13 = new Sphere(Vector(centroTronco3.x + -1.0, 1.0, centroTronco3.z + 6), 0.5);
    esfera13->SetFullMatte(morado);
    scene.AddSolidObject(esfera13);

    Sphere* esfera14 = new Sphere(Vector(centroTronco3.x + 2.0, -0.5, centroTronco3.z + 6), 0.5);
    esfera14->SetFullMatte(cyan);
    scene.AddSolidObject(esfera14);

    Sphere* esfera15 = new Sphere(Vector(centroTronco3.x + -2.0, -2.0, centroTronco3.z + 6.5), 0.5);
    esfera15->SetFullMatte(dorado);
    scene.AddSolidObject(esfera15);

    /**< Árbol 4. */
    Sphere* esfera16 = new Sphere(Vector(centroTronco4.x + 0.0, 4.0, centroTronco4.z + 5), 0.5);
    esfera16->SetFullMatte(rojo);
    scene.AddSolidObject(esfera16);

    Sphere* esfera17 = new Sphere(Vector(centroTronco4.x + 1.0, 2.5, centroTronco4.z + 5.5), 0.5);
    esfera17->SetFullMatte(azul);
    scene.AddSolidObject(esfera17);

    Sphere* esfera18 = new Sphere(Vector(centroTronco4.x + -1.0, 1.0, centroTronco4.z + 6), 0.5);
    esfera18->SetFullMatte(morado);
    scene.AddSolidObject(esfera18);

    Sphere* esfera19 = new Sphere(Vector(centroTronco4.x + 2.0, -0.5, centroTronco4.z + 6), 0.5);
    esfera19->SetFullMatte(cyan);
    scene.AddSolidObject(esfera19);

    Sphere* esfera20 = new Sphere(Vector(centroTronco4.x + -2.0, -2.0, centroTronco4.z + 6.5), 0.5);
    esfera20->SetFullMatte(dorado);
    scene.AddSolidObject(esfera20);

    /**< Árbol 5. */
    Sphere* esfera21 = new Sphere(Vector(centroTronco5.x + 0.0, 4.0, centroTronco5.z + 5), 0.5);
    esfera21->SetFullMatte(rojo);
    scene.AddSolidObject(esfera21);

    Sphere* esfera22 = new Sphere(Vector(centroTronco5.x + 1.0, 2.5, centroTronco5.z + 5.5), 0.5);
    esfera22->SetFullMatte(azul);
    scene.AddSolidObject(esfera22);

    Sphere* esfera23 = new Sphere(Vector(centroTronco5.x + -1.0, 1.0, centroTronco5.z + 6), 0.5);
    esfera23->SetFullMatte(morado);
    scene.AddSolidObject(esfera23);

    Sphere* esfera24 = new Sphere(Vector(centroTronco5.x + 2.0, -0.5, centroTronco5.z + 6), 0.5);
    esfera24->SetFullMatte(cyan);
    scene.AddSolidObject(esfera24);

    Sphere* esfera25 = new Sphere(Vector(centroTronco5.x + -2.0, -2.0, centroTronco5.z + 6.5), 0.5);
    esfera25->SetFullMatte(dorado);
    scene.AddSolidObject(esfera25);

     /**< Creación de los cubos / regalos . */

    Cuboid* cubo1 = new Cuboid(1.0, 1.0, 1.0);
    cubo1->Move(-4.0, -5.675, -91.0);
    cubo1->SetFullMatte(azul);
    cubo1->RotateX(-90.0);
    cubo1->RotateY(-22.0);
    scene.AddSolidObject(cubo1);

    Cuboid* cubo2 = new Cuboid(1.0, 1.0, 1.0);
    cubo2->Move(-1.0, -5.675, -91.0);
    cubo2->SetFullMatte(rojo);
    cubo2->RotateX(-90.0);
    cubo2->RotateY(-66.0);
    scene.AddSolidObject(cubo2);

    Cuboid* cubo3 = new Cuboid(2.0, 2.0, 1.5);
    cubo3->Move(-2.5, -5.175, -95.0);
    cubo3->SetFullMatte(dorado);
    cubo3->RotateX(-90.0);
    scene.AddSolidObject(cubo3);

    Cuboid* cubo4 = new Cuboid(1.0, 1.0, 1.0);
    cubo4->Move(-17.0, -5.675, -125.0);
    cubo4->SetFullMatte(morado);
    cubo4->RotateX(-90.0);
    cubo4->RotateY(-33.0);
    scene.AddSolidObject(cubo4);

    Cuboid* cubo5 = new Cuboid(1.0, 1.0, 1.0);
    cubo5->Move(10.0, -5.675, -145.0);
    cubo5->SetFullMatte(cyan);
    cubo5->RotateX(-90.0);
    cubo5->RotateY(-17.0);
    scene.AddSolidObject(cubo5);

    /**< Creación de las estrellas . */

    Optics* optics = new Optics();
    optics->SetMatteColor(Color(dorado));
    Vector t1Center = Vector (centroTronco1.x, centroTronco1.y + 13.0, centroTronco1.z + 3.0);
    Vector t2Center = Vector (centroTronco2.x, centroTronco2.y + 13.0, centroTronco2.z + 3.0);
    Vector t3Center = Vector (centroTronco3.x, centroTronco3.y + 13.0, centroTronco3.z + 3.0);
    Vector t4Center = Vector (centroTronco4.x, centroTronco4.y + 13.0, centroTronco4.z + 3.0);
    Vector t5Center = Vector (centroTronco5.x, centroTronco5.y + 13.0, centroTronco5.z + 3.0);

    TriangleMesh* estrella1 = new TriangleMesh(t1Center, false);
    estrella1->AddPoint(0, t1Center.x+-0.5, t1Center.y+ 0.5, t1Center.z);
    estrella1->AddPoint(1, t1Center.x+ 0.5, t1Center.y+ 0.5, t1Center.z);
    estrella1->AddPoint(2, t1Center.x+-0.5, t1Center.y+-0.5, t1Center.z);
    estrella1->AddPoint(3, t1Center.x+ 0.5, t1Center.y+-0.5, t1Center.z);
    estrella1->AddPoint(4, t1Center.x+-2, t1Center.y  , t1Center.z+3); //punta izquierda
    estrella1->AddPoint(5, t1Center.x+ 2, t1Center.y  , t1Center.z+3); //punta derecha
    estrella1->AddPoint(6, t1Center.x, t1Center.y+ -2, t1Center.z+3); //punta abajo
    estrella1->AddPoint(7, t1Center.x, t1Center.y+  2, t1Center.z+3); //punta arriba
    estrella1->AddPoint(8, t1Center.x, t1Center.y, t1Center.z+3); //centro

//    triangle1->AddTriangle(0,1,3,*optics);
    estrella1->AddTriangle(0,7,8,*optics);
    estrella1->AddTriangle(1,7,8,*optics);
    estrella1->AddTriangle(1,5,8,*optics);
    estrella1->AddTriangle(3,5,8,*optics);
    estrella1->AddTriangle(3,6,8,*optics);
    estrella1->AddTriangle(2,6,8,*optics);
    estrella1->AddTriangle(0,4,8,*optics);
    estrella1->AddTriangle(2,4,8,*optics);

    scene.AddSolidObject(estrella1);

    TriangleMesh* estrella2 = new TriangleMesh(t2Center, false);
    estrella2->AddPoint(0, t2Center.x+-0.5, t2Center.y+ 0.5, t2Center.z);
    estrella2->AddPoint(1, t2Center.x+ 0.5, t2Center.y+ 0.5, t2Center.z);
    estrella2->AddPoint(2, t2Center.x+-0.5, t2Center.y+-0.5, t2Center.z);
    estrella2->AddPoint(3, t2Center.x+ 0.5, t2Center.y+-0.5, t2Center.z);
    estrella2->AddPoint(4, t2Center.x+-2, t2Center.y  , t2Center.z+3); //punta izquierda
    estrella2->AddPoint(5, t2Center.x+ 2, t2Center.y  , t2Center.z+3); //punta derecha
    estrella2->AddPoint(6, t2Center.x, t2Center.y+ -2, t2Center.z+3); //punta abajo
    estrella2->AddPoint(7, t2Center.x, t2Center.y+  2, t2Center.z+3); //punta arriba
    estrella2->AddPoint(8, t2Center.x, t2Center.y, t2Center.z+3); //centro

//    triangle1->AddTriangle(0,1,3,*optics);
    estrella2->AddTriangle(0,7,8,*optics);
    estrella2->AddTriangle(1,7,8,*optics);
    estrella2->AddTriangle(1,5,8,*optics);
    estrella2->AddTriangle(3,5,8,*optics);
    estrella2->AddTriangle(3,6,8,*optics);
    estrella2->AddTriangle(2,6,8,*optics);
    estrella2->AddTriangle(0,4,8,*optics);
    estrella2->AddTriangle(2,4,8,*optics);

    scene.AddSolidObject(estrella2);

    TriangleMesh* estrella3 = new TriangleMesh(t3Center, false);
    estrella3->AddPoint(0, t3Center.x+-0.5, t3Center.y+ 0.5, t3Center.z);
    estrella3->AddPoint(1, t3Center.x+ 0.5, t3Center.y+ 0.5, t3Center.z);
    estrella3->AddPoint(2, t3Center.x+-0.5, t3Center.y+-0.5, t3Center.z);
    estrella3->AddPoint(3, t3Center.x+ 0.5, t3Center.y+-0.5, t3Center.z);
    estrella3->AddPoint(4, t3Center.x+-2, t3Center.y  , t3Center.z+3); //punta izquierda
    estrella3->AddPoint(5, t3Center.x+ 2, t3Center.y  , t3Center.z+3); //punta derecha
    estrella3->AddPoint(6, t3Center.x, t3Center.y+ -2, t3Center.z+3); //punta abajo
    estrella3->AddPoint(7, t3Center.x, t3Center.y+  2, t3Center.z+3); //punta arriba
    estrella3->AddPoint(8, t3Center.x, t3Center.y, t3Center.z+3); //centro

//    triangle1->AddTriangle(0,1,3,*optics);
    estrella3->AddTriangle(0,7,8,*optics);
    estrella3->AddTriangle(1,7,8,*optics);
    estrella3->AddTriangle(1,5,8,*optics);
    estrella3->AddTriangle(3,5,8,*optics);
    estrella3->AddTriangle(3,6,8,*optics);
    estrella3->AddTriangle(2,6,8,*optics);
    estrella3->AddTriangle(0,4,8,*optics);
    estrella3->AddTriangle(2,4,8,*optics);

    scene.AddSolidObject(estrella3);

    TriangleMesh* estrella4 = new TriangleMesh(t4Center, false);
    estrella4->AddPoint(0, t4Center.x+-0.5, t4Center.y+ 0.5, t4Center.z);
    estrella4->AddPoint(1, t4Center.x+ 0.5, t4Center.y+ 0.5, t4Center.z);
    estrella4->AddPoint(2, t4Center.x+-0.5, t4Center.y+-0.5, t4Center.z);
    estrella4->AddPoint(3, t4Center.x+ 0.5, t4Center.y+-0.5, t4Center.z);
    estrella4->AddPoint(4, t4Center.x+-2, t4Center.y  , t4Center.z+3); //punta izquierda
    estrella4->AddPoint(5, t4Center.x+ 2, t4Center.y  , t4Center.z+3); //punta derecha
    estrella4->AddPoint(6, t4Center.x, t4Center.y+ -2, t4Center.z+3); //punta abajo
    estrella4->AddPoint(7, t4Center.x, t4Center.y+  2, t4Center.z+3); //punta arriba
    estrella4->AddPoint(8, t4Center.x, t4Center.y, t4Center.z+3); //centro

//    triangle1->AddTriangle(0,1,3,*optics);
    estrella4->AddTriangle(0,7,8,*optics);
    estrella4->AddTriangle(1,7,8,*optics);
    estrella4->AddTriangle(1,5,8,*optics);
    estrella4->AddTriangle(3,5,8,*optics);
    estrella4->AddTriangle(3,6,8,*optics);
    estrella4->AddTriangle(2,6,8,*optics);
    estrella4->AddTriangle(0,4,8,*optics);
    estrella4->AddTriangle(2,4,8,*optics);

    scene.AddSolidObject(estrella4);

    TriangleMesh* estrella5 = new TriangleMesh(t5Center, false);
    estrella5->AddPoint(0, t5Center.x+-0.5, t5Center.y+ 0.5, t5Center.z);
    estrella5->AddPoint(1, t5Center.x+ 0.5, t5Center.y+ 0.5, t5Center.z);
    estrella5->AddPoint(2, t5Center.x+-0.5, t5Center.y+-0.5, t5Center.z);
    estrella5->AddPoint(3, t5Center.x+ 0.5, t5Center.y+-0.5, t5Center.z);
    estrella5->AddPoint(4, t5Center.x+-2, t5Center.y  , t5Center.z+3); //punta izquierda
    estrella5->AddPoint(5, t5Center.x+ 2, t5Center.y  , t5Center.z+3); //punta derecha
    estrella5->AddPoint(6, t5Center.x, t5Center.y+ -2, t5Center.z+3); //punta abajo
    estrella5->AddPoint(7, t5Center.x, t5Center.y+  2, t5Center.z+3); //punta arriba
    estrella5->AddPoint(8, t5Center.x, t5Center.y, t5Center.z+3); //centro

//    triangle1->AddTriangle(0,1,3,*optics);
    estrella5->AddTriangle(0,7,8,*optics);
    estrella5->AddTriangle(1,7,8,*optics);
    estrella5->AddTriangle(1,5,8,*optics);
    estrella5->AddTriangle(3,5,8,*optics);
    estrella5->AddTriangle(3,6,8,*optics);
    estrella5->AddTriangle(2,6,8,*optics);
    estrella5->AddTriangle(0,4,8,*optics);
    estrella5->AddTriangle(2,4,8,*optics);

    scene.AddSolidObject(estrella5);

    const double innerSize   = 0.0;
    const double xBorderSize = 50.0;
    const double yBorderSize = 80.0;
    const double thickness   = 0.50;

      /**< Superficie . */

    ChessBoard* mesa = new ChessBoard(
        innerSize,
        xBorderSize,
        yBorderSize,
        thickness,
        Color(0.24,0.16,0.11),
        Color(0.24,0.16,0.11),
        colorMesa);
    mesa->Move(0.0, -7.0, -150.0);
    mesa->RotateX(-90.0);
    mesa->SetMatteGlossBalance(0.5, Color(1.0, 1.0, 1.0, 1.0), Color(1.0, 1.0, 1.0, 1.0));
    scene.AddSolidObject(mesa);

      /**< Espejos. */

//    AddSceneMirrors(scene);

    /**< Poligono Convexo. */

    Cylinder* cilindroConvexo = new Cylinder(2.0, 4.0);
    cilindroConvexo->SetFullMatte(verde);
    cilindroConvexo->Move(0.0, 0.0, 0.0);//36.0, -19.5, -284.0
    cilindroConvexo->RotateX(-90.0);

    Cuboid* cuboConvexo = new Cuboid(3.0, 3.0, 1.0);
    cuboConvexo->Move(2.0, 0.0, 0.0);//
    cuboConvexo->SetFullMatte(verde);
    cuboConvexo->RotateX(-90.0);

    SetIntersection* poligonoConvexo1 = new SetDifference(Vector(0.0, 0.0, 0.0), cilindroConvexo, cuboConvexo);
    poligonoConvexo1->Move(15.0, -5.0, -104.0);
    poligonoConvexo1->RotateY(-10.0);

    scene.AddSolidObject(poligonoConvexo1);

    //Agregamos 3 luces, izquierda, derecha y la del centro..
    scene.AddLightSource(LightSource(Vector(0.0, 10.0, -10.0), Color(1.0, 1.0, 1.0, 1.0)));
    scene.AddLightSource(LightSource(Vector(70.0, 10.0, -100.0), Color(1.0, 1.0, 1.0, 1.0)));
    scene.AddLightSource(LightSource(Vector(-70.0, 10.0, -100.0), Color(1.0, 1.0, 1.0, 1.0)));

    // Generate a JPG file that displays the scene...
    const char *filename = "Arboles_de_Navidad.jpg";
    scene.SaveImage(filename,1200, 720, 4.5, 4); //4 en AntiAliasing
    std::cout << "Se escribio la escena: " << filename << std::endl;

}

//---------------------------------------------------------------------------
// Define a new type that is a pointer to a function
// with void return type and taking zero arguments.
typedef void (* COMMAND_FUNCTION) ();

struct CommandEntry
{
    const char* verb;           // the command line option
    COMMAND_FUNCTION command;   // function to call when option encountered
    const char* help;           // usage text that explains the option
};

// You can add more command line options to this program by
// adding another entry to the array below.
// Each item in the ray is a string followed by a
// function to be called when that string appears
// on the command line.
const CommandEntry CommandTable[] =
{
    { "escena", Escena,
        "    Concrete block with a sphere casting a shadow on it.\n"
    },
};

// Calculate the number of entries in CommandTable[]...
const size_t NUM_COMMANDS = sizeof(CommandTable) / sizeof(CommandTable[0]);


void PrintUsageText()
{
    using namespace std;

    cout <<
        "Ray Tracer demo - Copyright (C) 2013 by Don Cross.\n"
        "For more info, see: http://cosinekitty.com/raytrace\n"
        "\n"
        "The following command line options are supported:\n";

    for (size_t i=0; i < NUM_COMMANDS; ++i)
    {
        cout << "\n";
        cout << CommandTable[i].verb << "\n";
        cout << CommandTable[i].help;
    }

    cout << endl;
}


int main(int argc, const char *argv[])
{
    using namespace std;

    int rc = 1;

    if (argc == 1)
    {
        // No command line arguments are present, so display usage text.
        PrintUsageText();
    }
    else
    {
        // There is at least one command line option present.
        // Search the command table for the matching verb.
        const string verb = argv[1];
        bool found = false;     // did we find a matching verb in the table?
        for (size_t i=0; i < NUM_COMMANDS; ++i)
        {
            if (verb == CommandTable[i].verb)
            {
                found = true;                   // we found a match!
                CommandTable[i].command();      // call the function
                rc = 0;                         // indicate success
                break;                          // stop searching
            }
        }

        if (!found)
        {
            cerr << "ERROR:  Unknown command line option '" << verb << "'" << endl;
        }
    }
    return rc;
}
