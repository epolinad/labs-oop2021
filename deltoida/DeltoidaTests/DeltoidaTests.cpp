#include "pch.h"
#include "CppUnitTest.h"
#include "../Deltoida/Deltoida.h"
#include "../Deltoida/Deltoida.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DeltoidaTests
{
    TEST_CLASS(DeltoidaTests)
    {
    public:

        TEST_METHOD(DeltoidaDefaultConstructor)
        {
            Prog2::Deltoida d;
            Assert::AreEqual(0.0, d.getP().x);
            Assert::AreEqual(0.0, d.getP().y);
            Assert::AreEqual(1.0, d.getR());
        }

        TEST_METHOD(DeltoidaInitConstructors)
        {
            Prog2::Deltoida d(3);
            Prog2::Point p(2, 3);
            Assert::AreEqual(0.0, d.getP().x);
            Assert::AreEqual(0.0, d.getP().y);
            Assert::AreEqual(3.0, d.getR());

            Prog2::Deltoida d2(p, 8);
            Assert::AreEqual(2.0, d2.getP().x);
            Assert::AreEqual(3.0, d2.getP().y);
            Assert::AreEqual(8.0, d2.getR());

            Prog2::Deltoida d3(-5, -7, 15);
            Assert::AreEqual(-5.0, d3.getP().x);
            Assert::AreEqual(-7.0, d3.getP().y);
            Assert::AreEqual(15.0, d3.getR());
        }

        TEST_METHOD(ConstructorExceptions)
        {
            Assert::ExpectException<std::exception>([] {Prog2::Deltoida d(-1); });//lambda function
            Assert::ExpectException<std::exception>([] {
                Prog2::Point p(2, 3);
                Prog2::Deltoida d(p, -3);
                });
            Assert::ExpectException<std::exception>([] {Prog2::Deltoida d(5, -15.5, -9); });
        }

        TEST_METHOD(Setters)
        {
            Prog2::Deltoida a;
            Prog2::Point p1(3, 2);
            a.setP(p1);
            Assert::AreEqual(3.0, a.getP().x);
            Assert::AreEqual(2.0, a.getP().y);
            Prog2::Point p2(-3, -2);
            a.setP(p2);
            Assert::AreEqual(-3.0, a.getP().x);
            Assert::AreEqual(-2.0, a.getP().y);
            a.setR(2);
            Assert::AreEqual(2.0, a.getR());
            Assert::ExpectException<std::exception>([] {
                Prog2::Deltoida a;
                a.setR(-1);
                });
        }

        TEST_METHOD(DeltoidaParameters)
        {
            Prog2::Deltoida d1;
            const double PI = 3.14159, err = 0.00001;
            Assert::AreEqual(2 * PI, d1.area(), err);
            Assert::AreEqual(16.0, d1.perimeter(), err);
            Assert::AreEqual(4.0, d1.intersection_length(), err);
            Assert::AreEqual(0.664458, d1.coord(1).x, err); //2*r*cos(1) + r*cos(2) + p.x | p.x=0
            Assert::AreEqual(0.773645, d1.coord(1).y, err); //2*r*sin(1) - r*sin(2) + p.y | p.y=0
            Assert::AreEqual(3.0, d1.coord(0).x, err); //2*r*cos(0) + r*cos(0) + p.x | p.x=0
            Assert::AreEqual(0.0, d1.coord(0).y, err); //2*r*sin(0) - r*sin(0) + p.y | p.y=0
            Assert::AreEqual("{x = 2.00cos(t) + 1.00cos(2t) + 0.00, y = 2.00sin(t) - 1.00sin(2t) + 0.00}\n", d1.frm());

            Prog2::Deltoida d2(1, 3, 2);
            Assert::AreEqual(2 * PI * 2 * 2, d2.area(), err); //2pi * r^2
            Assert::AreEqual(16.0 * 2, d2.perimeter(), err); // 16*r
            Assert::AreEqual(4.0 * 2, d2.intersection_length(), err); //4 * r
            Assert::AreEqual(2.32892, d2.coord(1).x, err); //2*r*cos(1) + r*cos(2) + p.x | p.x=1
            Assert::AreEqual(4.54729, d2.coord(1).y, err); //2*r*sin(1) - r*sin(2) + p.y | p.y=3
            Assert::AreEqual(7.0, d2.coord(0).x, err); //2*r*cos(0) + r*cos(0) + p.x | p.x=1
            Assert::AreEqual(3.0, d2.coord(0).y, err); //2*r*sin(0) - r*sin(0) + p.y | p.y=3
            Assert::AreEqual("{x = 4.00cos(t) + 2.00cos(2t) + 1.00, y = 4.00sin(t) - 2.00sin(2t) + 3.00}\n", d2.frm());
        }
    };
}