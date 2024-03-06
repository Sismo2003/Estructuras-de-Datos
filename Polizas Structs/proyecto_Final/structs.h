#ifndef POLICESFUNCTIONS_H
#define POLICESSTRUCT_H

struct date
{
    int day;
    char month[3];
    int year;
};

struct addres
{
    char street[20];
    char suburb[20];
    char city[20];
    char state[20];
    char country[3];
    char streetNumber[5];
    char innerNumber[5];
};
struct person{
    char name[15];
    char lastname[15];
    struct date birth;
    struct addres addres;
    int age;
    char contactPhone[10];
    char contactMail[20];
};

struct policyGeneral{
    float deductible;
    char coverage[15];
    float price;
    float sumAssured;
    struct date vigency;
};

struct policyOwner{
    char name[15];
    char lastname[15];
    char contactPhone[10];
    char contactMail[20];
    struct addres addres;
};

struct policyCar{
    char model[10];
    char brand[10];
    int serialNumber;
    int year;
};

struct policyBuissnes{
    struct addres addresInsured;
};
struct policyHome{
    struct addres addresInsured;
};

struct policyLife{
    struct person beneficiary;
    struct person insured;
};

union policyType{
    struct policyBuissnes Buissnes;
    struct policyHome Home;
    struct policyCar Car;
    struct policyLife Life;
};

struct policy{
    int id;
    union policyType type;
    struct policyGeneral genaralData;
    struct policyOwner policyOwner;
};

#endif // POLICES_H
