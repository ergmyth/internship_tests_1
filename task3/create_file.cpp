//
// Created by Earl Leonarda on 15/02/2020.
//

#include "task3.hpp"

void	create_file(t_main *s)
{
	ofstream myfile;
	myfile.open("result.csv");//get abs of scoop ok ko
	myfile << "Попыток налить, Процент ошибок, Налитый объем, Не налитый объем,";
	myfile << "Попыток забрать, Процент ошибок, Забранный объем, Не забранный объем,";
	myfile << "Объем в начале периода, Объем в конце периода\n";
	myfile << s->top_up->attempts << ",";
	myfile << (s->top_up->attempts - s->top_up->attempts_ok) * 100.0 / s->top_up->attempts;
	myfile << "," << s->top_up->ok_value << "," << s->top_up->ko_value << ",";
	myfile << s->scoop->attempts << ",";
	myfile << (s->scoop->attempts - s->scoop->attempts_ok) * 100.0 / s->scoop->attempts;
	myfile << "," << -s->scoop->ok_value << "," << -s->scoop->ko_value << ",";
	myfile << s->volume_start << "," << s->volume_end;
	myfile.close();
	cout << "File is created" << endl;
}
