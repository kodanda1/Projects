/**
 * @file Shape.cpp
 *
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "Shape.h"
#include "Polygon.h"

Shape::Shape()
{
    mSink.SetComponent(this);

}

void Shape::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    //Component::Draw(graphics, GetPosition().x, GetPosition().y);
    Component::Draw(graphics, x, y);
    //DrawPolygon(graphics,500,700);

}
void Shape::SetImage(std::wstring imagesDir)
{
    Polygon::SetImage(imagesDir);


}

