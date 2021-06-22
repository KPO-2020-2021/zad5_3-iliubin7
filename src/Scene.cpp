#include "../inc/Scene.hpp"


 Scene::Scene()
 {

        Lacze.ZmienTrybRys(PzG::TR_3D);

       Lacze.UstawZakresY(-300, 300);
       Lacze.UstawZakresX(-300, 300);
       Lacze.UstawZakresZ(-300, 300);
       
       double tab_s[3]={600,600,0};
       Vector3D size_bottom(tab_s);
       bottom=new Surface(size_bottom,20);
       Vector3D cent;
       for(int i=0; i<4; i++)
  {
  cent[0] = rand() % 400 - 200;
  cent[1] = rand() % 400 - 200;
  cent[2] = 50;
  int nr_p=rand()%3;
   if(nr_p==0)
  List_of_elements.push_front(std::make_shared<Mount>(cent, 100, 50, 100, "../datasets/Element" + std::to_string(nr_elem) + ".dat"));
 else if(nr_p==1)
  List_of_elements.push_front(std::make_shared<Plateau>(cent, 100, 50, 100, "../datasets/Element" + std::to_string(nr_elem) + ".dat"));
   else if(nr_p==2)
  List_of_elements.push_front(std::make_shared<Plane>(cent, 100, 50, 100, "../datasets/Element" + std::to_string(nr_elem) + ".dat"));
  nr_elem++;
  }
  for (std::list<std::shared_ptr<Scene_object>>::const_iterator a = List_of_elements.begin(); a != List_of_elements.end(); a++)
  {
    Lacze.DodajNazwePliku((*a)->get_name().c_str());
    (*a)->write_to_file();
  }

  Lacze.DodajNazwePliku(bottom->get_name().c_str());
  bottom->write_to_file();
  for (int i = 0; i < N; i++)
  {
    double position[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};
    List_of_drons.push_front(std::make_shared<Dron>(i, Lacze, Vector3D(position))) ;
    List_of_elements.push_front(*List_of_drons.begin());
    (*List_of_drons.begin())->write_to_file();
    nr_dron++;
  }

       Lacze.Rysuj();
 }
 void  Scene::draw()
 {
     
   Lacze.Rysuj();
 }

 bool  Scene::interface()
 {
  cout << "a - wybierz aktywnego drona" << endl;
  cout << "d - dodaj element powierzchni (lub drona)" << endl;
  cout << "u - usun element powierzchni" << endl;
  cout << "k - usun drona" << endl;
  char op;
  cin >> op;
  switch(op)
  {
  case 'a':
  {
    cout << "Wprowadz numer aktywnego drona, 0 lub 1: " << endl;
    for(int i=0; i<(int)List_of_drons.size(); i++)
    {
      cout<<i <<" ";
    }
    cout<<":"<<endl;
    int nr;
    cin >> nr;
    std::list<std::shared_ptr<Dron>>::const_iterator a;
    a=List_of_drons.begin();
    for(int i=0; i<nr; i++)
    {
      a++;
    }
    
    (*a)->control(List_of_elements);
  }
  break;
  case 'd':
  {
    cout << "Wybierz rodzaj powierzchniowego elementu" << endl;
    cout << "1 - Gora z ostrym szczytem" << endl;
    cout << "2 - Gora z grania" << endl;
    cout << "3 - Plaskowyz" << endl;
    cout << "4 - Dron" << endl;
  
    int nr;
    cin >> nr;
    Vector3D cent;

    cent[0] = rand() % 400 - 200;
    cent[1] = rand() % 400 - 200;
    cent[2] = 50;

   if( nr!= 4)
   { 
    if (nr == 1)
    {

      List_of_elements.push_front(std::make_shared<Mount>(cent, 100, 50, 100, "../datasets/Element" + std::to_string(nr_elem) + ".dat"));
    }
    if (nr == 2)
    {

      List_of_elements.push_front(std::make_shared<Plane>(cent, 100, 50, 100, "../datasets/Element" + std::to_string(nr_elem) + ".dat"));
    }
    if (nr == 3)
    {

      List_of_elements.push_front(std::make_shared<Plateau>(cent, 100, 50, 100, "../datasets/Element" + std::to_string(nr_elem) + ".dat"));
    }
    nr_elem++;
    (*List_of_elements.begin())->write_to_file();
    Lacze.DodajNazwePliku((*List_of_elements.begin())->get_name().c_str());
  }
  else
{
  double postition[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};
  List_of_drons.push_front(std::make_shared<Dron>(nr_dron, Lacze, Vector3D(postition)));
  List_of_elements.push_front(*List_of_drons.begin());
  (*List_of_drons.begin())->write_to_file();
}
 }
  break;
  case 'u':
  {
    int i = 0;
    for (std::list<std::shared_ptr<Scene_object>>::const_iterator a = List_of_elements.begin(); a != List_of_elements.end(); a++)
    {
      cout << i << ": " << (*a)->get_name() << endl;
      i++;
    }
    cout << "podaj numer" << endl;

    int nr;
    cin >> nr;
    std::list<std::shared_ptr<Scene_object>>::const_iterator a = List_of_elements.begin();

    for (int j = 0; j < nr; j++)
    {

      a++;
    }
    
    Lacze.UsunNazwePliku((*a)->get_name());
    List_of_elements.erase(a); // usuwa z llinijki List_of_elements zaczynajac od symbolu z indeksem a i do konca linijki
  }
  break;
  case 'k':
  {
    int i = 0;
    for (std::list<std::shared_ptr<Dron>>::const_iterator a = List_of_drons.begin(); a != List_of_drons.end(); a++)
    {
      cout << i << ": " << (*a)->get_id() << endl;
      i++;
    }
    cout << "podaj numer" << endl;

    int nr;
    cin >> nr;
    std::list<std::shared_ptr<Dron>>::const_iterator a = List_of_drons.begin();

    for (int j = 0; j < nr; j++)
    {

      a++;
    }
    
   (*a)->del_obj();
    List_of_drons.erase(a); // usuwa z llinijki List_of_elements zaczynajac od symbolu z indeksem a i do konca linijki
  }
  break;

  default:
    break;
 }
  return true;
}


 Scene::~Scene()
 {
free(bottom);
 }