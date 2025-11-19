#include "Zombie.hpp"
#include <iostream>

int main(void) {

	Zombie *ghoul= newZombie("kaneki");
	randomChump("ken");
	ghoul->announce();
	delete ghoul;

	Zombie z;
	z.announce();
	Zombie zz("zz");
	zz.announce();
	{
	Zombie zom("zom");
	zom.announce();
	}
	return 0;
}

//kanekiはnewZombieのnewのタイミングでコンストラクタが呼ばれ、deleteでデストラクタ
//kenはrandomChump内でコンストラクタからデストラクタまで

//z~zomはコンストラクタは作られた順だが、デストラクタはスコープが終わるタイミング
//同じスコープ内では後に作ったものが先に破棄される(zz->zの順でデストラクタ)
