// TEMA 6. 
/*
Se dau următoarele clase :
- Abonament(string nume_abonament, float pret, int perioadă)
- Abonament_Premium(int reducere) : Abonament
- Persoană(int id, string nume, string cnp)
- Abonat(string nr_telefon, abonament x) : Persoana
Să se construiască clasa Clienți care reține o listă de abonați.
Să se afle numărul de abonați premium.
Să se realizeze o metodă care află care este suma de bani încasată de 
la toți abonații considerând perioada ca fiind nr de luni si prețul este plătit pe fiecare lună.
*/


#include "Clienti.h"

int main()
{
    //
    Abonament ab();
    Abonament* er = new Abonament("prepay", 333.45, 12);
    er->Print();
    //
    Abonament_Premium Abp();
    Abonament_Premium* er_p1 = new Abonament_Premium(*er, 40);
    er_p1->Print();
    Abonament_Premium* er_p2 = new Abonament_Premium(Abonament("rafs", 14.8, 90), 14);
    er_p2->Print();
    Abonament* er_p3 = new Abonament_Premium(Abonament("bcr", 33.85, 653), 11);
    er_p3->Print();
    
    Abonament_Premium er_p("vodf", 4.0001, 10, 4);
    er_p.Print();
    Abonament er2("alib", 7.45, 122);
    er2.Print();
    //
    std::cout << "\n\n------------------AFISARI--------------------\n\n";
    std::cout << er2;
    std::cout << er_p;
    std::cout << *er;
    std::cout << *er_p2;
    std::cout << *er_p3;
    std::cout << *(Abonament_Premium*)er_p3; // "cast" pentru a putea afisa informatiile clasei derivate;
    // Putem face operatii de "cast" doar cu POINTERI de tipul unei clase!
    //
    std::cout << "DYNAMIC CAST:";
    std::cout << "\n" << *dynamic_cast<Abonament_Premium*>(er_p3); // Abonament* er_p3;
    std::cout << *dynamic_cast<Abonament*>(er_p2); // Abonament_Premium* er_p2;
    /// std::cout << *dynamic_cast<Abonament_Premium*>(er); // NU FUNCTIONEAZA CU DYNAMIC CAST
    /// std::cout << *(Abonament_Premium*)er; // "int reducere" va afisa o valoare random;
    //
    //
    std::cout << "\n\n-----------------\n\n";
    Abonament c1(*er_p3), c2(er_p)/*cast automat*/, c3(er2);
    std::cout << c1;
    std::cout << c2;
    std::cout << c3;
    Abonament_Premium d1(*dynamic_cast<Abonament_Premium*>(er_p3)), d2(er_p);
    std::cout << d1;
    std::cout << d2;
    d2 = *dynamic_cast<Abonament_Premium*>(er_p3);
    std::cout << d2;
    c3 = er_p; /*cast automat*/
    er_p = *er_p2;
    std::cout << c3;
    std::cout << c3;
    std::cout << er_p;
    *er_p1 = er_p;
    std::cout << *er_p1;
    er2 = *er;
    std::cout << er2;
    //
    //
    std::cout << "\n\n---------------CITIRI------------------\n\n";
/*
    Abonament ab1;
    std::cin >> ab1;
    std::cout << ab1;
*/

/*
    Abonament_Premium abp1;
    std::cin >> abp1;
    std::cout << abp1;
*/

/*
    Abonament* ab2 = new Abonament();
    std::cin >> *ab2;
    std::cout << *ab2;
    delete ab2;
*/

/*
    Abonament_Premium* abp2 = new Abonament_Premium();
    std::cin >> *abp2;
    std::cout << *abp2;
    delete abp2;
*/

/*
    Abonament* abq = new Abonament_Premium();
    std::cin >> *dynamic_cast<Abonament_Premium*>(abq);
    std::cout << *abq;
    Abonament_Premium abq1 = *dynamic_cast<Abonament_Premium*>(abq);
    std::cout << abq1;
    delete abq;
*/

    //
    //
    std::cout << "\n\n--------------------------------------------------\n\n";
    Persoana p1, p2(), p3(43244, "Ionescu Marian", "67445465"), p4(p3);
    Persoana* pp1 = new Persoana();
    Persoana* pp2 = new Persoana(54355, "Popescu Tudor", "143314");
    Persoana* pp3 = new Persoana(p4);
    Persoana* pp4 = new Persoana(*pp2);
    std::cout << p1;
    std::cout << p3;
    std::cout << p4;
    std::cout << *pp1;
    std::cout << *pp2;
    std::cout << *pp3;
    std::cout << *pp4;
    ///////////////
    Abonat q1, q2(), q3(1234, "Pop Alex", "4636", "0745", er);
    //std::cout << q3;
    Abonat q4(*new Persoana(4232, "Gica Ian", "311"), "076434", &er2);
    //std::cout << q4;
    q4.Print();
    Abonat q5(q4);
    q5.Print();
    std::cout << "\n\n";
    Abonat* qq1 = new Abonat();
    Abonat* qq2 = new Abonat(1, "Pop Ilie", "341", "785", er);
    std::cout << qq2->get_type_Abonament().name() << "  TEST\n";
    qq2->Print();
    Abonat* qq3 = new Abonat(p3, "0707", er_p3);
    std::cout << qq3->get_type_Abonament().name() << "  TEST\n";
    std::cout << "\n\n" << (qq2->get_type_Abonament() == qq3->get_type_Abonament()) << "\n\n";
    qq3->Print();
    er_p.Print();
    std::cout << typeid(*er).name() << "\n";
    std::cout << typeid(er_p).name() << "\n";
    std::cout << (typeid(*er) == typeid(er_p)) << "\n";
    std::cout << (typeid(*er) == typeid(er2)) << "\n\n\n";
    //
    std::cout << "-----------------ALTE TESTE DESPRE CLASA <<ABONAT>>-------------------\n\n";
    std::cout << "----------AFISARI-------------\n\n";
    //
    Abonat* qqq1 = new Abonat(123, "Nicusor Rares", "4524542545", "0745455312", new Abonament("orange", 46.1456, 12));
    Abonat* qqq2 = new Abonat(124, "Ciortan Dan", "24313111", "0365675764", new Abonament_Premium("digi", 23.78, 24, 15));
    std::cout << "PRIMUL:\n\n";
    std::cout << *qqq1;
    std::cout << "AL DOILEA:\n\n";
    std::cout << *qqq2;
    std::cout << qqq1->get_type_Abonament().name() << "  TEST2\n";
    std::cout << qqq2->get_type_Abonament().name() << "  TEST2\n\n\n";
    //
    Abonat qqq3 = Abonat(*qq2);
    std::cout << qqq3;
    std::cout << " TEST3\n";
    Abonat qqq4(q4);
    std::cout << qqq4;
    std::cout << " TEST4\n\n\n";
    //
    Abonat* r1 = new Abonat(125, "Nicu Gigel", "74577577", "0316575747", er_p2);
    std::cout << *r1;
    std::cout << typeid(*er_p2).name() << "\n";
    std::cout << r1->get_type_Abonament().name();
    std::cout << " TEST5\n\n";
    Abonat r2(126, "Florescu Ian", "6577377537", "0753633542", er_p3);
    std::cout << r2;
    std::cout << typeid(*er_p3).name() << "\n";
    std::cout << r2.get_type_Abonament().name();
    std::cout << " TEST6\n\n";
    Abonat r3(127, "Popa Marius", "432413", "03231", er);
    std::cout << r3;
    std::cout << typeid(*er).name() << "\n";
    std::cout << r3.get_type_Abonament().name();
    std::cout << " TEST7\n\n";
    std::cout << typeid(Abonament).name() << "\n"; // "class Abonament"
    std::cout << typeid(Abonament_Premium).name() << "\n"; // "class Abonament_Premium"
    ///////////////
    ///////////////
    r3 = r2;
    *r1 = r3;
    std::cout << *r1;
    std::cout << r3;
    std::cout << "\n\n" << r1->get_type_Abonament().name();
    std::cout << "\n\n" << r3.get_type_Abonament().name() << "\n\n\n";
    //
    *pp1 = *pp2;
    std::cout << *pp2;
    std::cout << *pp1 << "\n";
    p3 = *pp1;
    std::cout << p3 << "\n";
    ///////////////
    std::cout << "\n----------------------CITIRI--------------------------\n\n";
/*
    Persoana* pa = new Persoana();
    std::cin >> *pa;
    std::cout << *pa;
    delete pa;
*/

/*
    Persoana pa2;
    std::cin >> pa2;
    std::cout << pa2;
*/

/*
    Persoana* pa3 = new Abonat();
    std::cin >> *(Abonat*)pa3;
    std::cout << *(Abonat*)pa3;
    delete pa3;
*/

/*
    Abonat* pa4 = new Abonat();
    std::cin >> *pa4;
    std::cout << *pa4;
    delete pa4;
*/

    //////////////////////////
    std::cout << "\n\n---------------------------CLIENTI TESTE---------------------------\n\n";
    Clienti* cl1 = new Clienti();
    cl1->Push_Abonat(&r3);
    cl1->Push_Abonat(qqq1);
    cl1->Print();
    Clienti cl2;
    cl2.Push_Abonat(qqq2);
    cl2.Push_Abonat(&qqq3);
    cl2.Push_Abonat(&qqq4);
    cl2.Push_Abonat(new Abonat(1234, "Badea Dan", "123456789", "07898989", new Abonament_Premium("fbk", 17.11, 5, 6)));
    cl2.Push_Abonat(new Abonat(12345, "Varna Ion", "674747", "072323", new Abonament("spc", 11.8, 15)));
    std::cout << *cl1;
    std::cout << cl2;
    std::cout << "\n\n\n\n\n";

    *cl1 = cl2;
    std::cout << *cl1;
    std::cout << cl2 << "\n\n\n\n\n";
    cl1->Print();
    std::cout << "\n\n";
    //////////////////////////
    std::cout << "\n\n------------------Check Constructors---------------------\n\n";
    Clienti* cl3 = new Clienti(*cl1);
    std::cout << *cl3;
    std::vector<Abonat*> va;
    va.push_back(qqq1);
    va.push_back(&r3);
    va.push_back(qqq2);
    Clienti cl4(va);
    std::cout << cl4 << "\n\n";
    //////////////////////////
    std::cout << "\n\n-----------------CITIRI CLIENTI--------------------\n\n";

/*
    Clienti* cl5 = new Clienti();
    std::cin >> *cl5;
    std::cout << *cl5;
    delete cl5;
*/

/*
    Clienti cl6;
    std::cin >> cl6;
    std::cout << cl6;
*/
    
    std::cout << "\n\n------------------Contract Teste---------------------\n\n";
    Contract* ct1 = new Abonament_Premium();
    ///////////////
    delete ct1;

    std::cout << "\n\n------------------Contract Teste---------------------\n\n";
    Contract* ct2 = new Abonament();

    ///////////////
    delete ct2;

    /// !! Si in cele 3 cazuri de mai jos se apeleaza constructorul din CONTRACT class!
    std::cout << "\n\n------------------Teste---------------------\n\n\n\n\n";
    Abonament* abb1 = new Abonament();
    delete abb1;
    std::cout << "\n\n------------------Teste---------------------\n\n";
    Abonament* abb2 = new Abonament_Premium();
    delete abb2;
    std::cout << "\n\n------------------Teste---------------------\n\n";
    Abonament_Premium* abb3 = new Abonament_Premium();
    delete abb3;
    std::cout << "\n\n------------------Teste---------------------\n\n\n\n\n";
    //////////////////////////
    Clienti clg;
    Contract* ctg1 = new Abonament("quant", 45.505, 24);
    Abonat abg(222, "Popa Cosmin", "545476", "075563", (Abonament*)ctg1); // explicit cast needed if we use a CONTRACT pointer;
    std::cout << abg;
    Contract* ctg2 = new Abonament_Premium(*(Abonament*)ctg1, 9);
    Abonat abg2(333, "Ionescu Ion", "76567", "036464784", (Abonament_Premium*)ctg2); // explicit cast needed if we use a CONTRACT pointer;
    std::cout << abg2;
    std::cout << "\n----------PRINT Contract-------------\n";
    //
    ctg2->Print(); // pure virtual function
    std::cout << "\n----------PRINT Contract-------------\n";
    ctg1->Print(); // pure virtual function
    //
    std::cout << "\n----------PRINT Contract-------------\n";
    Abonament* ctg3 = new Abonament_Premium(*(Abonament*)ctg2, 41);
    Abonat abg3(444, "Popescu Alex", "674876", "0732142320", ctg3); 
    std::cout << abg3;

    Abonament_Premium* ctg4 = new Abonament_Premium(*(Abonament_Premium*)ctg2);
    Abonat abg4(555, "Dorin Mihai", "223232", "03123456", ctg4);
    std::cout << abg4;
    /////
    clg.Push_Abonat(&abg);
    clg.Push_Abonat(&abg2);
    std::cout << clg;
    clg.Push_Abonat(&abg3);
    clg.Push_Abonat(&abg4);
    std::cout << clg;
    //
    std::cout << "\n\n--------------------std::move-------------------------\n\n";
/*
    Abonament ma1(std::move(Abonament("sunfl", 12.56, 6))), ma2;
    std::cout << ma1;
    std::cout << ma2;
    ma2 = std::move(ma1);
    //ma2 = ma1;
    std::cout << ma1;
    std::cout << ma2;
    Abonament ma3(ma1);
    std::cout << ma3;
*/
    /////////
    std::cout << "\n\n---------------------SUM + NR.AB----------------------------\n\n";
    std::cout << *cl3;
    std::cout << "Nr. abonati: " << cl3->get_nr_Ab() << "\n\n";
    std::cout << "Nr. abonati_premium: " << cl3->get_nr_Ab_Premium() << "\n\n";
    std::cout << "Suma totala de bani(euro): " << cl3->total_sum_ab() << "\n\n\n\n";
    cl4.Push_Abonat(new Abonat(Persoana(54221, "Gantz Marius", "57896"), "07545365", new Abonament_Premium("amazon", 67.891, 30, 2)));
    std::cout << cl4;
    std::cout << "Nr. abonati: " << cl4.get_nr_Ab() << "\n\n";
    std::cout << "Nr. abonati_premium: " << cl4.get_nr_Ab_Premium() << "\n\n";
    std::cout << "Suma totala de bani(euro): " << cl4.total_sum_ab() << "\n\n\n\n";
    //
    std::cout << "---------------CITIRE CL.-------------------\n\n";
/*
    Clienti* cl5 = new Clienti();
    std::cin >> *cl5;
    std::cout << *cl5;
    std::cout << "Nr. abonati: " << cl5->get_nr_Ab() << "\n\n";
    std::cout << "Nr. abonati_premium: " << cl5->get_nr_Ab_Premium() << "\n\n";
    std::cout << "Suma totala de bani(euro): " << cl5->total_sum_ab() << "\n\n\n\n";
    delete cl5;
*/
    ////
    std::cout << "\n\n-----------------STATIC-------------------\n\n";
    Contract* ctt1;
    ctt1 = new Abonament();
    ctt1->Print();
    Contract* ctt2 = new Abonament_Premium();
    ctt2->Print();
    delete ctt2;
    ctt1->Print();
    Abonament aabb1;
    aabb1.Print();
    Abonament_Premium* aabb2 = new Abonament_Premium();
    aabb2->Print();
    Abonament* aabb3 = new Abonament_Premium();
    aabb3->Print();
    ///
    Contract::set_nr_total_Contracte_to_zero();
    std::cout << "Nr. total de contracte in momentul actual: " << Contract::get_nr_total_Contracte() << "\n\n";
    aabb3->Print();
    aabb1.Print();
    std::cout << "Nr. total de contracte in momentul actual: " << Contract::get_nr_total_Contracte() << "\n\n";
    ///
    Contract* ctt3 = new Abonament_Premium();
    std::cout << "Nr. total de contracte in momentul actual: " << Contract::get_nr_total_Contracte() << "\n\n";
    Contract* ctt4 = new Abonament("google", 31.99, 6);
    std::cout << "Nr. total de contracte in momentul actual: " << Contract::get_nr_total_Contracte() << "\n\n";
    Abonament_Premium* aabb4 = new Abonament_Premium();
    std::cout << "Nr. total de contracte in momentul actual: " << Contract::get_nr_total_Contracte() << "\n\n";
    delete ctt3;
    delete aabb4;
    std::cout << "Nr. total de contracte in momentul actual: " << Contract::get_nr_total_Contracte() << "\n\n";
    Abonament* aabb5 = new Abonament_Premium(*(Abonament*)ctt4, 3);
    std::cout << *(Abonament_Premium*)aabb5;
    std::cout << "Nr. total de contracte in momentul actual: " << Contract::get_nr_total_Contracte() << "\n\n";
    Contract::set_nr_total_Contracte_to_zero();
    std::cout << "Nr. total de contracte in momentul actual: " << Contract::get_nr_total_Contracte() << "\n\n";
    delete ctt4;
    delete aabb5;
    std::cout << "Nr. total de contracte in momentul actual: " << Contract::get_nr_total_Contracte() << "\n\n";
    //
    // EXEMPLU DE SMART POINTERS!!
    std::cout << "\n\n---------------SMART POINTERS--------------------\n\n";
    std::cout << "---------UNIQUE----------\n\n";
    std::unique_ptr<Contract> su_c1 = std::make_unique<Abonament>("HP", 45.59, 12);
    std::unique_ptr<Contract> su_c2 = std::make_unique<Abonament_Premium>(Abonament("wi", 8.99, 24), 5);
    std::unique_ptr<Contract> su_c3 = std::move(su_c2);
    std::unique_ptr<Contract> su_c4 = std::move(su_c1);
    std::cout << "\n\n---------SHARED----------\n\n";
    std::shared_ptr<Contract> ss_c1 = std::make_shared<Abonament>("sony", 14.09, 4);
    std::shared_ptr<Contract> ss_c2 = std::make_shared<Abonament_Premium>(*std::dynamic_pointer_cast<Abonament>(ss_c1), 7);
    std::shared_ptr<Abonament> ss_c3 = std::make_shared<Abonament_Premium>("microsoft", 18.15, 12, 10);
    std::shared_ptr<Abonament_Premium> ss_c4 = std::make_shared<Abonament_Premium>(*std::make_shared<Abonament>("nokia", 98, 72), 12);
    std::cout << *std::dynamic_pointer_cast<Abonament>(ss_c1);
    std::cout << *std::dynamic_pointer_cast<Abonament_Premium>(ss_c2);
    std::cout << *ss_c3;
    std::cout << *std::dynamic_pointer_cast<Abonament_Premium>(ss_c3);
    std::cout << "\n\n" << *ss_c4;
    std::cout << *std::dynamic_pointer_cast<Abonament>(ss_c4);
    std::cout << "\n\n-----------WEAK------------\n\n";
    std::weak_ptr<Contract> sw_c1;
    sw_c1 = ss_c1;
    std::weak_ptr<Abonament> sw_c3 = ss_c3;
    ////
    //
    //     
    // CITIREA DE LA TASTATURA A "N" OBIECTE DE DIFERITE TIPURI!!
/*
    std::cout << "\n\n\n-----------------CITIREA A <<N>> OBIECTE DE DIFERITE TIPURI-------------------\n\n\n";
    Contract::set_nr_total_Contracte_to_zero();
    std::cout << "Momentan sunt: " << Contract::get_nr_total_Contracte() << " contracte/abonamente(simple sau premium):\n\n\n";
    unsigned short nr_obiecte;
    std::cout << "Dati nr. de abonamente ce vor fi citite de la tastatura: ";
    std::cin >> nr_obiecte;
    std::vector<std::shared_ptr<Contract>> abonamente;
    std::cout << "\n\n--------CITIRE----------\n\n";
    for (int i = 0; i < nr_obiecte; i++)
    {
        std::shared_ptr<Contract> temp;
        std::cout << "\n\nAbonamentul nr. " << i + 1 << ":\n";
        unsigned short alegere;
        std::cout << "Apasati <<1>> pt. un abonament(simplu) sau <<2>> pt. un abonament_premium: ";
        std::cin >> alegere;
        if (alegere == 1)
        {
            temp = std::make_shared<Abonament>();
            std::cin >> *std::dynamic_pointer_cast<Abonament>(temp);
            abonamente.push_back(temp);
        }
        else if (alegere == 2)
        {
            temp = std::make_shared<Abonament_Premium>();
            std::cin >> *std::dynamic_pointer_cast<Abonament_Premium>(temp);
            abonamente.push_back(temp);
        }
        else
        {
            std::cout << "\nProgramul se va opri deoarece a fost introdusa o alegere invalida!!!\n";
            exit(-1199);
        }
    }
    std::cout << "\n\n---------AFISARE----------\n\n";
    std::cout << "S-au creat " << Contract::get_nr_total_Contracte() << " contracte/abonamente(simple sau premium):\n\n\n";
    nr_obiecte = abonamente.size();
    for (int i = 0; i < nr_obiecte; i++)
    {
        std::cout << "\n\nAbonamentul nr. " << i + 1 << ":\n";
        if (typeid(*abonamente[i]) == typeid(Abonament))
        {
            std::cout << *std::dynamic_pointer_cast<Abonament>(abonamente[i]);
        }
        else
        {
            std::cout << *std::dynamic_pointer_cast<Abonament_Premium>(abonamente[i]);
        }
    }
*/
    //
    //
    ////
    std::cout << "\n\n---------DELETION PART----------\n\n";
    ///
    delete er;
    delete er_p1;
    delete er_p2;
    delete er_p3;
    ///////////////
    delete pp1;
    delete pp2;
    delete pp3;
    delete pp4;
    delete qq1;
    delete qq2;
    delete qq3;
    delete qqq1;
    delete qqq2;
    delete r1;
    delete cl1;
    delete cl3; 
    delete ctg1;
    delete ctg2;
    delete ctg3;
    delete ctg4;
    ///////////////
    delete ctt1;
    delete aabb2;
    delete aabb3;

    return 0;
}



/// Citirea stringurilor se face FARA SPATII!!!