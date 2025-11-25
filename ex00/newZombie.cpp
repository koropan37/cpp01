#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie( std::string name ) {
	return new Zombie(name);
}
//newはヒープにメモリを確保してコンストラクタを呼び、ポインタを返す。
//deleteはデストラクタをよんで、メモリを開放する。
//片方だけ使うのは危険(leak)
//ヒープに置かないとこの関数が終わったときにNULLになる
//Zombie zombie(name); return &zombie; はだめ
