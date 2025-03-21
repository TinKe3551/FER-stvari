#include <iostream>
#include <deque>
#include <csignal>
#include <map>
#include <signal.h>


using namespace std;

string K_Z = "00000";
deque<string> suSto;
map<string, int> ostalo;
// GP - je li trenutna radnja glavni program
// t brojac
// T_P - tekuci prioritet

void ispis_stanja(string radnja, bool povecaj_vr)
{

    if (povecaj_vr)
        cout << "--------vrijeme t" << ++ostalo["t"] << "--------\n";

    cout << "> " << radnja << '\n';

    cout << "K_Z: " << K_Z << "; ";

    string TPbin = "00000";
    if (ostalo["T_P"] > 0)
        TPbin[ostalo["T_P"] - 1] = '1';
    cout << "T_P: " << TPbin << '\n';

    cout << "sistemski stog (od najkasnije dodanog do najranije dodanog elementa):\n";
    for (string i : suSto)
        cout << i << ' ';

    cout << endl;
}

void obrada_signala(int signal)
{

    ostalo["GP"] = 0;

    int prioritet;

    switch (signal)
    {

    case SIGHUP:
        prioritet = 1;
        break;

    case SIGUSR1:
        prioritet = 2;
        break;

    case SIGQUIT:
        prioritet = 3;
        break;

case SIGTRAP:
        prioritet = 4;
	break;

    case SIGABRT:
        prioritet = 5;
        break;

    default:
        break;
    }

    K_Z[prioritet - 1] = '1';
    // cout << "> K_Z: " << K_Z << '\n';
    ispis_stanja("u registar K_Z upisuje se zastavica za prekid prioriteta " + to_string(prioritet), true);

    if (ostalo["T_P"] >= prioritet)
    {
        cout << "> nastavlja se s obradom prekida prioriteta " << ostalo["T_P"] << '\n';
        return;
    }

    suSto.emplace_front("reg[" + to_string(ostalo["T_P"]) + "]");
    string TPbin = "00000";
    if (ostalo["T_P"] != 0)
        TPbin[ostalo["T_P"] - 1] = '1';
    suSto.emplace_front(TPbin);

    bool prvi_prolaz = true;

    for (ostalo["T_P"] = prioritet; ostalo["T_P"] > 0 && suSto.front()[ostalo["T_P"] - 1] == '0';)
    {

        if (K_Z[ostalo["T_P"] - 1] == '0')
        {
            ostalo["T_P"]--;
            continue;
        }

        // if (suSto.front()[ostalo["T_P"] - 1] == '1' || ostalo["T_P"] == 0) break;

        K_Z[ostalo["T_P"] - 1] = '0';

        if (prvi_prolaz)
        {
            ispis_stanja("spremanje konteksta", true);
            ispis_stanja("obrada signala prioriteta " + to_string(ostalo["T_P"]), false);
            prvi_prolaz = false;
        }
        else
            ispis_stanja("obrada prekida prioriteta " + to_string(ostalo["T_P"]), true);

        for (int i = 0; i < 5; i++)
            sleep(1);
    }

    int t;
    for (t = 5; t > 0 && suSto.front()[t - 1] == '0'; t--)
        ;

    suSto.pop_front();
    suSto.pop_front();

    ispis_stanja("obnova konteksta", true);

    if (t > 0)
        ispis_stanja("jos uvijek traje obrada signala prioriteta " + to_string(t), false);
    else
    {
        ostalo["GP"] = 1;
        ispis_stanja("nastavak rada glavnog programa", false);
    }
}

int main(void)
{

    signal(SIGHUP, obrada_signala);
    signal(SIGUSR1, obrada_signala);
    signal(SIGQUIT, obrada_signala);
    signal(SIGTRAP, obrada_signala);
    signal(SIGABRT, obrada_signala);

    int PID = getpid();
    cout << "signali poredani od najmanjeg do najveceg prioriteta:\n";
    cout << "1 SIGHUP\n";
    cout << "2 SIGUSR1\n";
    cout << "3 SIGQUIT\n";
    cout << "4 SIGTRAP\n";
    cout << "5 SIGABRT\n";
    cout << "\nPID" << PID << '\n';
    cout << "program se prekida slanjem signala SIGINT\n\n";

    ostalo["GP"] = false;
    ostalo["t"] = -1;

    for (;;)
    {

        if (!ostalo["GP"])
        {
            ispis_stanja("glavni program", true);
            ostalo["GP"] = 1;
        }
    }

    return 0;
}
