#ifndef АИП_ЛАБЫ_GENERATOR_H
#define АИП_ЛАБЫ_GENERATOR_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "abiturient.h"

const char* firstnames[] = {
        "Ivan", "Petr", "Aleksandr", "Aleksey", "Anatoliy", "Andrey", "Anton",
        "Artyom", "Boris", "Vadim", "Valentin", "Valeriy", "Vasiliy", "Viktor",
        "Vitaliy", "Vladimir", "Vladislav", "Vyacheslav", "Gennadiy", "Georgiy",
        "Gleb", "Grigoriy", "Daniil", "Denis", "Dmitriy", "Yevgeniy", "Yegor",
        "Zakhar", "Igor", "Ilya", "Kirill", "Konstantin", "Leonid", "Maksim",
        "Matvey", "Mihail", "Nikita", "Nikolay", "Oleg", "Pavel", "Roman",
        "Ruslan", "Semyon", "Sergey", "Stanislav", "Stepan", "Timur", "Fedor",
        "Yuri", "Yaroslav", "Artem", "David", "Seyran", "Ali", "Rostislav",
        "Marat", "Ruslan", "Rustam", "Damir", "Arsen", "Renat", "Albert",
        "Edward", "Robert", "Alex", "Mark", "Lev", "Platon", "Innokentiy",
        "Vsevolod", "Svyatoslav", "Miron", "Taras", "Savely", "Eduard", "Samson",
        "Yakov", "German", "Gavriil", "Demyan", "Vladlen", "Bogdan", "Zinovy",
        "Ippolit", "Kuzma", "Lavrentiy", "Makar", "Naum", "Panteleymon", "Prokhor",
        "Rodion", "Saveliy", "Tikhon", "Trofin", "Fadey", "Feodor", "Filip",
        "Khariton", "Yermolay", "Yulian", "Yakov"
};

const char* lastnames[] = {
        "Ivanov", "Petrov", "Sidorov", "Smirnov", "Kuznetsov", "Morozov", "Orlov",
        "Fyodorov", "Popov", "Kozlov", "Lebedev", "Volkov", "Titov", "Sokolov",
        "Grishin", "Kazakov", "Kovalev", "Platonov", "Gusev", "Isaev", "Medvedev",
        "Novikov", "Pavlov", "Frolov", "Zhukov", "Nikolaev", "Karpov", "Zaitsev",
        "Solovyov", "Vinogradov", "Bogdanov", "Vlasov", "Saveliev", "Egorov",
        "Krylov", "Tarasov", "Komarov", "Shcherbakov", "Mikhailov", "Belov",
        "Belyaev", "Golubev", "Kotov", "Lazarev", "Suvorov", "Korolev", "Panov",
        "Fomin", "Davydov", "Zhuravlev", "Gerasimov", "Ignatov", "Kudryavtsev",
        "Lobanov", "Merkushev", "Nikitin", "Osipov", "Potapov", "Rybakov",
        "Simonov", "Ushakov", "Filippov", "Chernov", "Shishkin", "Yakovlev",
        "Antonov", "Baranov", "Voronov", "Gavrilov", "Dorofeev", "Yefimov",
        "Zakharov", "Ilyin", "Klimov", "Lapin", "Maslov", "Naumov", "Ovchinnikov",
        "Polovtsev", "Rodionov", "Stepanov", "Timofeev", "Uvarov", "Khlebnikov",
        "Tsyganov", "Cherkasov", "Shchukin", "Yudin", "Avdeev", "Biryukov",
        "Vasilyev", "Gorbunov", "Dementiev", "Yermolaev", "Zhdanov", "Kolesnikov",
        "Lisin", "Mironov", "Nekrasov", "Ponomarev", "Rogov", "Sobolev"
};

const char* middlenames[] = {
        "Ivanovich", "Petrovich", "Alekseyevich", "Dmitriyevich", "Sergeyevich",
        "Yegorovich", "Maksimovich", "Aleksandrovich", "Viktorovich", "Denisovich",
        "Vladimirovich", "Ilich", "Arturovich", "Romanovich", "Matveevich",
        "Kirillovich", "Andreevich", "Georgievich", "Danilovich", "Artemovich",
        "Borisovich", "Valeryevich", "Gennadyevich", "Grigoryevich", "Leonidovich",
        "Mikhaylovich", "Nikolayevich", "Olegovich", "Pavlovich", "Romanovich",
        "Stanislavovich", "Timurovich", "Fyodorovich", "Yuryevich", "Yaroslavovich",
        "Anatolyevich", "Vadimovich", "Vitalyevich", "Vyacheslavovich", "Zakharovich",
        "Igorevich", "Konstantinovich", "Lvovich", "Ruslanovich", "Semyonovich",
        "Tarasovich", "Filippovich", "Eduardovich", "Yakovlevich", "Artyomovich",
        "Arkadyevich", "Bogdanovich", "Vasilyevich", "Glebovich", "Daniilovich",
        "Yevgenyevich", "Zinovievich", "Innokentyevich", "Korneyevich", "Levovich",
        "Makarovich", "Naumovich", "Ostapovich", "Prokopyevich", "Rodionovich",
        "Savelyevich", "Tikhonovich", "Ustinovich", "Fomich", "Kharitonovich",
        "Yefimovich", "Yaropolkovich", "Afanasyevich", "Vsevolodovich", "Gavrilovich",
        "Dmitrievich", "Yeliseyevich", "Zosimovich", "Ippolitovich", "Kuzmich",
        "Larionovich", "Mstislavovich", "Nazarovich", "Onisimovich", "Panteleimonovich",
        "Rostislavovich", "Svyatoslavovich", "Trofimovich", "Ulyanovich", "Feodosievich",
        "Kharitonovich", "Yemelyanovich", "Yaroslavich", "Avramovich", "Boleslavovich",
        "Venediktovich", "Gennadievich", "Dormidontovich", "Yeremeyevich", "Zakharievich",
        "Iosifovich", "Kasyanovich", "Lukich", "Mitrofanovich", "Nikonovich"
};

const char* specialities[] = {
        "Computer Science", "Mathematics", "Physics", "Biology", "Chemistry",
        "History", "Law", "Psychology", "Data Science", "Machine Learning",
        "Business Administration", "Political Science", "Economics", "Linguistics",
        "Philosophy", "Engineering", "Medicine", "Architecture", "Art History",
        "Journalism", "International Relations", "Environmental Science",
        "Neuroscience", "Artificial Intelligence", "Cybersecurity"
};

Abiturient generate_abiturient(bool print_info) {
    Abiturient abit;
    const char* lastname = lastnames[rand() % (sizeof(lastnames) / sizeof(lastnames[0]))];
    const char* firstname = firstnames[rand() % (sizeof(firstnames) / sizeof(firstnames[0]))];
    const char* middlename = middlenames[rand() % (sizeof(middlenames) / sizeof(middlenames[0]))];
    snprintf(abit.name, sizeof(abit.name), "%s %s %s", lastname, firstname, middlename);
    strcpy(abit.speciality, specialities[rand() % (sizeof(specialities) / sizeof(specialities[0]))]);
    abit.exam_score = rand() % 301;
    abit.rank = 1 + (rand() % 1000);
    abit.original_document = rand() % 2;

    if (print_info) {
        printf("%-50s %-20s %-5d %-5d %s\n",
               abit.name,
               abit.speciality, abit.exam_score, abit.rank,
               abit.original_document ? "Да" : "Нет");
    }
    return abit;
}


#endif //АИП_ЛАБЫ_GENERATOR_H
