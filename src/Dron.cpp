#include "../inc/Dron.hpp"

Dron::Dron(int id, PzG::LaczeDoGNUPlota &Lacze, Vector3D position) : Lacze(Lacze)
{
    angle=0;
    this->id = id;
    orginal.set_name("../datasets/korpus" + std::to_string(id) + ".dat");

    for (int i = 0; i < 4; i++)
        oryg_rotor[i].set_name("../datasets/rotor" + std::to_string(i) + std::to_string(id) + ".dat");

    Lacze.DodajNazwePliku(orginal.get_name().c_str());
    for (int i = 0; i < 4; i++)
        Lacze.DodajNazwePliku(oryg_rotor[i].get_name().c_str());
    copy = orginal;
    radius_of_dron = copy.radius();

    copy.translate(position);
    for (int i = 0; i < 4; i++)
        copy_rotor[i] = oryg_rotor[i];

    for (int i = 0; i < 4; i++)
        copy_rotor[i].translate(orginal[i * 2] + position);

    this->way = this->way + position;
}

void Dron::lifting(double way)
{
    Vector3D way_o;
    way_o[2] = way;

    this->way = this->way + way_o;
    copy.rotation(rot);
    copy.translate(this->way);
}

void Dron::translate(double way)
{
    Vector3D way_o;
    way_o[0] = way * cos(angle * M_PI / 180);
    way_o[1] = way * sin(angle * M_PI / 180);
    this->way = this->way + way_o;
    copy.rotation(rot);
    copy.translate(this->way);
}

void Dron::rotate(double angle)
{
    this->angle += angle;
    Matrix3D matr;
    rot = matr * matrix_rot_z(this->angle);
    copy.rotation(rot);
    copy.translate(this->way);
}
void Dron::rotor_rotation()
{
    static int angle = 0;
    angle += 3;
    if (angle == 360)
        angle = 0;

    Matrix3D matr;
    matr = matr * matrix_rot_z(angle);
    for (int i = 0; i < 4; i++)
    {
        copy_rotor[i].rotation(matr);
    }

    for (int i = 0; i < 4; i++)
    {
        copy_rotor[i].translate(copy[i * 2]);
    }
}

void Dron::write_to_file()
{
    copy.write_to_file();
    for (int i = 0; i < 4; i++)
        copy_rotor[i].write_to_file();
}

void Dron::way_by_circle(double r)
{
   double  a=(r*2)/sqrt(4+2*sqrt(2));
//promien
        def_way(r,0);
        Lacze.DodajNazwePliku("../datasets/way.dat");
        for (int i = 0; i < 100; i++)
        {
            copy = orginal;
            for (int j = 0; j < 4; j++)
                copy_rotor[j] = oryg_rotor[j];
            lifting(1);
            rotor_rotation();
            write_to_file();
            Lacze.Rysuj();
            usleep(TIME);
        }
                for (int i = 0; i < r; i++)
        {
            copy = orginal;
            for (int j = 0; j < 4; j++)
                copy_rotor[j] = oryg_rotor[j];
            translate(1);
            rotor_rotation();
            write_to_file();
            Lacze.Rysuj();
            usleep(TIME);
        }
 // pierwszy obrot
  def_way(a,112);
        for (int i = 0; i < 112; i++)
            {
                copy = orginal;
                for (int i = 0; i < 4; i++)
                    copy_rotor[i] = oryg_rotor[i];
                rotate(1);
                rotor_rotation();
                write_to_file();
                Lacze.Rysuj();
                usleep(TIME);
            }
                for (int i = 0; i < a; i++)
        {
            copy = orginal;
            for (int j = 0; j < 4; j++)
                copy_rotor[j] = oryg_rotor[j];
            translate(1);
            rotor_rotation();
            write_to_file();
            Lacze.Rysuj();
            usleep(TIME);
        }

    for(int i=0; i<7; i++)
    {
        def_way(a,45);
        for (int i = 0; i < 45; i++)
            {
                copy = orginal;
                for (int i = 0; i < 4; i++)
                    copy_rotor[i] = oryg_rotor[i];
            rotate(1);
            rotor_rotation();
            write_to_file();
            Lacze.Rysuj();
            usleep(TIME);
            }
                for (int i = 0; i < a; i++)
        {
            copy = orginal;
            for (int j = 0; j < 4; j++)
                copy_rotor[j] = oryg_rotor[j];
            translate(1);
            rotor_rotation();
            write_to_file();
            Lacze.Rysuj();
            usleep(TIME);
        }
  
    }

        for (int i = 0; i < 113; i++)
            {
                copy = orginal;
                for (int i = 0; i < 4; i++)
                    copy_rotor[i] = oryg_rotor[i];
            rotate(1);
            rotor_rotation();
            write_to_file();
            Lacze.Rysuj();
            usleep(TIME);
            }
                for (int i = 0; i < r; i++)
        {
            copy = orginal;
            for (int j = 0; j < 4; j++)
                copy_rotor[j] = oryg_rotor[j];
            translate(1);
            rotor_rotation();
            write_to_file();
            Lacze.Rysuj();
            usleep(TIME);
        }
            for (int i = 0; i < 100; i++)
        {
            copy = orginal;
            for (int j = 0; j < 4; j++)
                copy_rotor[j] = oryg_rotor[j];
            lifting(-1);
            rotor_rotation();
            write_to_file();
            Lacze.Rysuj();
            usleep(TIME);
        }
       Lacze.UsunNazwePliku("../datasets/way.dat");
}

void Dron::control()
{
    double way;
    double angle;
    double r;
    char op;

    write_to_file();
    cout << "p - przesuniecie\n";
    cout << "o - obrot\n";
    cout << "c - ruch po okregu\n";
    cout << "opcje :";
    cin >> op;
    switch (op)
    {
    case 'p':
        cout << "podaj dlugosc lotu: ";
        cin >> way;
        def_way(way, angle);
        Lacze.DodajNazwePliku("../datasets/way.dat");
        for (int i = 0; i < 100; i++)
        {
            copy = orginal;
            for (int j = 0; j < 4; j++)
                copy_rotor[j] = oryg_rotor[j];
            lifting(1);
            rotor_rotation();
            write_to_file();
            Lacze.Rysuj();
            /*!
            * Uzywamy ta funkcje dlatego, zeby byla widoczna animacja drona. 
            * Ta funckja zawiesza wykonanie na czas wyrazony w mikrosekundach.
            */
            usleep(TIME);
        }

        for (int i = 0; i < way; i++)
        {
            copy = orginal;
            for (int j = 0; j < 4; j++)
                copy_rotor[j] = oryg_rotor[j];
            translate(1);
            rotor_rotation();
            write_to_file();
            Lacze.Rysuj();
            usleep(TIME);
        }

        for (int i = 0; i < 100; i++)
        {
            copy = orginal;
            for (int j = 0; j < 4; j++)
                copy_rotor[j] = oryg_rotor[j];
            lifting(-1);
            rotor_rotation();
            write_to_file();
            Lacze.Rysuj();
            usleep(TIME);
        }
    Lacze.UsunNazwePliku("../datasets/way.dat");
        break;
    case 'o':
        cout << "podaj kierunek lotu (kat w stopniach): ";
        cin >> angle;
        if (angle > 0)
        {
            for (int i = 0; i < angle; i++)
            {
                copy = orginal;
                for (int i = 0; i < 4; i++)
                    copy_rotor[i] = oryg_rotor[i];
                rotate(1);
                rotor_rotation();
                write_to_file();
                Lacze.Rysuj();
                usleep(TIME);
            }
        }
        else
        {
            for (int i = 0; i > angle; i--)
            {
                copy = orginal;
                rotate(-1);
                rotor_rotation();
                write_to_file();
                Lacze.Rysuj();
                usleep(TIME);
            }
        }

        break;
        case 'c':
        cout << "podaj promien okregu\n";
        cin >> r;
        way_by_circle(r);
        break;
    default:
        break;
    }
}

void Dron::def_way(double way,double angle)
{
    Vector3D next = copy.get_center();
    next[2] = 0;
    dron_way.push_back(next);
    next[2] = 100;
    dron_way.push_back(next);
    next[0] += way * cos(angle * M_PI / 180);
    next[1] += way * sin(angle * M_PI / 180);
    dron_way.push_back(next);
    next[2] = 0;
    dron_way.push_back(next);

    std::fstream file;

    file.open("../datasets/way.dat", std::ios::out);
    for (int i = 0; i < (int)dron_way.size(); i++)
    {

        file << dron_way[i] << std::endl;
    }
    file.close();
}
void Dron::del_obj()
  {
    Lacze.UsunNazwePliku(orginal.get_name().c_str());
    for (int i = 0; i < 4; i++)
        Lacze.UsunNazwePliku(oryg_rotor[i].get_name().c_str());
  }
 bool Dron::check_collision(shared_ptr <Scene_object> ob)
 {
    std::shared_ptr<Dron> self = shared_from_this();
     if (ob != self) // zeby nie wykrywalo kolizje samego ze soba.
    {

        Vector3D center_of_dron = copy.get_center();
        Vector3D center_of_object = ob->get_center();
        double l = sqrt(pow(center_of_dron[0] - center_of_object[0], 2) + pow(center_of_dron[1] - center_of_object[1], 2) + pow(center_of_dron[2] - center_of_object[2], 2));
        if (radius_of_dron + ob->radius() >= l)
        {
            return true;
        }
    }
    return false;
 }

 Vector3D Dron::get_center() const
 {
   return copy.get_center();
 }