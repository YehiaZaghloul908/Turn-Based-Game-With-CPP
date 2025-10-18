#include <iostream>
#include <cstdlib>
using namespace std;

class player
{
private:
    const int MAX_HP = 25;
    int hp;
    const int MAX_STAMINA = 5;
    const int PLAYER_WEAPON_COUNT = 3;
    int stamina;
    string name;

public:
    player()
    {
        hp = MAX_HP;
        stamina = MAX_STAMINA;
        cout << "A player has spawned!" << endl;
        cout << "Enter your name: ";
        cin >> name;
    };
    ~player()
    {
        cout << "The player has been defeated!" << endl;
    }
    void setHp()
    {
        cin >> hp;
    }
    int currentHp()
    {
        return hp;
    }
    void setStamina()
    {
        cin >> stamina;
    }
    void setName()
    {
        cin >> name;
    }
    int returnWeaponCount()
    {
        return PLAYER_WEAPON_COUNT;
    }
    int returnCurrentStamina()
    {
        return stamina;
    }
    void hurt(int damage)
    {
        hp -= damage;
        cout << name << "'s hp has been reduced to " << hp << endl;
    }
    int shiningBlade() // better to be a class
    {
        string attackName = "Shining Blade"; // doesn't really have a purpose except if this was class
        int damage = 5;
        stamina -= 1;
        cout << name << " has casted " << attackName << endl;
        cout << "Current stamina is " << stamina << endl;
        return damage;
    }
    int skullCrusher() // better to be a class
    {
        string attackName = "Skull Crusher"; // doesn't really have a purpose except if this was class
        int damage = 20;
        stamina -= 3;
        cout << name << " has casted " << attackName << endl;
        cout << "Current stamina is " << stamina << endl;
        return damage;
    }
    void rest()
    {
        stamina = MAX_STAMINA;
        cout << name << "'s stamina has fully restored!" << endl;
        cout << "Current stamina is " << stamina << endl;
    }
};

class enemy
{
private:
    int hp = 50;
    string name = "Enemy";

public:
    enemy()
    {
        cout << "An enemy has spawned" << endl;
    }
    ~enemy()
    {
        cout << "The enemy has been defeated" << endl;
    }
    void setHp()
    {
        cin >> hp;
    }
    int currentHp()
    {
        return hp;
    }
    void setName()
    {
        cin >> name;
    }
    void hurt(int damage)
    {
        hp -= damage;
        cout << name << "'s hp has been reduced to " << hp << endl;
    }
    int feetTickler() // better to be a class
    {
        string attackName = "Feet Tickler"; // doesn't really have a purpose except if this was class
        int damage = 5;
        cout << name << " has casted " << attackName << endl;
        return damage;
    }
};

main()
{
    player p1;
    enemy enemy1;

    bool enemyDefeated = false;
    bool playerDefeated = false;
    while (!enemyDefeated && !playerDefeated)
    {
        int choice = 0;
        cout << "======================================================" << endl;
        cout << "Your turn is up, choose one of the following actions: " << endl;
        cout << "1- Shining Blade (5 damage) (-1 stamina)" << endl;
        cout << "2- Skull Crusher (20 damage) (-3 stamina)" << endl;
        cout << "3- Rest (fully restore stamina)" << endl;

        int choicePhaseDone = false;
        while (((choice <= 0) || (choice > p1.returnWeaponCount())) && !choicePhaseDone)
        {
            cout << "Enter Choice: ";
            cin >> choice;
            system("cls");

            if (choice == 1)
            {
                if (p1.returnCurrentStamina() >= 1) // hard coded need optimization
                {
                    enemy1.hurt(p1.shiningBlade());
                    choicePhaseDone = true;
                }
                else
                {
                    cout << "Not enough stamina!!!" << endl;
                }
            }
            else if (choice == 2)
            {
                if (p1.returnCurrentStamina() >= 3) // hard coded need optimization
                {
                    enemy1.hurt(p1.skullCrusher());
                    choicePhaseDone = true;
                }
                else
                {
                    cout << "Not enough stamina!!!" << endl;
                }
            }
            else if (choice == 3)
            {
                p1.rest();
                choicePhaseDone = true;
            }
            else
            {
                cout << "Please choose a valid option" << endl;
            }
        }

        if (choicePhaseDone)
        {
            p1.hurt(enemy1.feetTickler());
        }

        int enemyHp = enemy1.currentHp();
        int playerHp = p1.currentHp();

        if (enemyHp <= 0)
        {
            enemyDefeated = true;
            cout << "===========================================" << endl;
            cout << "CONGRATULATIONS YOU HAVE DEFEATED THE ENEMY" << endl;
            cout << "===========================================" << endl;
        }
        else if (playerHp <= 0)
        {
            playerDefeated = true;
            cout << "====================================================" << endl;
            cout << "sorry... you have been defeated.... try again later." << endl;
            cout << "====================================================" << endl;
        }
    }

    int x;
    cin >> x;
    return 0;
}