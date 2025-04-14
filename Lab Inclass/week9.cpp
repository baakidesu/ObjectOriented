#include <iostream>

class SlashingWeapon;

class Weapon{
protected:
    int durability, damage;
    char type;

public:
    Weapon(int _durability, int _damage, char _type) {
        durability = _durability;
        damage = _damage;
        type = _type;
    }
    virtual void Hit(int& targetHP, int slashingArmor, int piercingArmor) {}
};

class SlashingWeapon : public Weapon {
protected:
    int sharpness;

public:
    SlashingWeapon(int durability, int damage, int sharpness ,char type): Weapon(durability, damage, type) {
       this->sharpness = sharpness;
    }
    void Hit(int& targetHP, int slashingArmor, int piercingArmor) override {
        std::cout << "[DEBUG] SLASHING WEAPON HIT" << std::endl;

        targetHP -= (damage-slashingArmor) * sharpness;
        durability -= slashingArmor/2;
        sharpness -= 0.15;

        if (targetHP <= 0) {
            targetHP = 0;
            std::cout << "Target is dead!" << std::endl;
        }
    }
};

class PiercingWeapon : public Weapon {
protected:
    int thickness;
    int momentum = 0;

public:
    PiercingWeapon(int durability, int damage, int thickness ,char type): Weapon(durability, damage, type) {
        this->thickness = thickness;
    }

    void Hit(int& targetHP, int slashingArmor, int piercingArmor) override {
        std::cout<<"[DEBUG] PIERCING WEAPON HIT" << std::endl;

        if (durability <= 0) {
            std::cout <<"Can't make attack because durability is: " << durability << std::endl;
        }else if (durability > 0) {
            targetHP -= (damage-piercingArmor) * thickness + momentum;
            durability -= 2*piercingArmor;
            momentum++;
        }

        if (targetHP <= 0) {
            targetHP = 0;
        }

    }
};

int main() {

    //Enemy infos
    int targetHP, slashingArmor, piercingArmor;

    std::cout <<"Type enemy hp, it's slashing armor and piercing armor values: ";
    std::cin >> targetHP >> slashingArmor >> piercingArmor;

    //Weapon infos
    int durability, damage, sharpness;
    char type;
    std::cout <<"Type weapon's durability, damage and it's type ";
    std::cin >> durability >> damage >> type;

    Weapon* weapon = nullptr;

    if (type == 's') {
        int sharpness;
        std::cout<< "Type weapon's sharpness: ";
        std::cin >> sharpness;
        weapon = new SlashingWeapon(durability, damage, sharpness, type);
    }else if (type == 'p') {
        int thickness;
        std::cout<< "Type weapon's thickness: ";
        std::cin >> thickness;
        weapon = new PiercingWeapon(durability, damage, thickness, type);
    }

    for (int i = 0; i<5; i++) {
        weapon->Hit(targetHP, slashingArmor, piercingArmor);
    }

    delete weapon;
    std::cout <<"Target hp is: " << targetHP << std::endl;
}