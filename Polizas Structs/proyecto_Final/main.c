#include <stdio.h>
#include "structs.h"
#include <string.h>
#include <unistd.h>

void datashowall(struct policy *p , int *id , int *policyType ){
    int ans = 0;
    printf("\nIngrese el Numero de Folio a Consultar: ");
    scanf("%d",&ans);
    if(policyType[ans] == 0){
        printf("\nUna disculpa tu folio %d no hasido encontrado con exito.\n", &ans);
    }
    if(policyType[ans] >=1 || policyType[ans] <= 4){
        //policyowner
        printf("\nLa Informacion de su Folio es: \n");
        printf("\n########################################################\n");
        printf("\nEl nombre bajo el folio es: %s \n", p[ans].policyOwner.name);
        printf("\nEl apellido bajo el folio es: %s \n", p[ans].policyOwner.lastname);
        printf("\nEl telefono de contacto es: %s \n", p[ans].policyOwner.contactPhone);
        printf("\nEl Email de contacto es: %s \n", p[ans].policyOwner.contactMail);

        printf("\nLa suma asegurada es: $%0.f \n", p[ans].genaralData.sumAssured);
        printf("\nEl deducible es de : $%2.f \n", p[ans].genaralData.deductible);
        printf("\nLa cobertura es : $%s \n", p[ans].genaralData.coverage);
        printf("\nEl precio de la covertura es: $%0.f \n", p[ans].genaralData.price);
        printf("\nLa Vigencia es: %d/%s/%d \n", p[ans].genaralData.vigency.day,p[ans].genaralData.vigency.month,p[ans].genaralData.vigency.year);

        printf("\nLa dirrecion del contacto es: %s con el numero %s \n", p[ans].policyOwner.addres.street, p[ans].policyOwner.addres.streetNumber);
        printf("\nEn la ciudad: %s \n", p[ans].policyOwner.addres.city);
        printf("\nEn el estado: %s \n", p[ans].policyOwner.addres.state);
        printf("\nEn el pais: %s \n", p[ans].policyOwner.addres.country);

        if(policyType[ans] == 1 ){
            printf("\nSu poliza es de Negocio\n");
            //struct de dirrecion, type
			printf("\nLa dirrecion de la poliza es: %0.s \n", *p[ans].type.Buissnes.addresInsured.street);
            printf("\nCon el numero: %s \n", p[ans].type.Buissnes.addresInsured.streetNumber);
            printf("\nLa ciudad es:: %s \n", p[ans].type.Buissnes.addresInsured.city);
            printf("\nEn el estado: %s \n", p[ans].type.Buissnes.addresInsured.state);
            printf("\nEn el pais: %s \n", p[ans].type.Buissnes.addresInsured.country);
            //STRUCT de GeneralData

        }
        if (policyType[ans] == 2){
            printf("\nSu poliza de Vivienda: \n");
            printf("\nLa dirrecion de la poliza es: %0.s \n", p[ans].type.Home.addresInsured.street);
            printf("\nCon el numero: %s \n", p[ans].type.Home.addresInsured.streetNumber);
            printf("\nLa ciudad es:: %s \n", p[ans].type.Home.addresInsured.city);
            printf("\nEn el estado: %s \n", p[ans].type.Home.addresInsured.state);
            printf("\nEn el pais: %s \n", p[ans].type.Home.addresInsured.country);


 
        }
        if(policyType[ans] == 3){
            printf("\nSu poliza de carro: \n");
            printf("\nEl modelo del carro es: %s", p[ans].type.Car.model);
            printf("\nLa marca del auto es: %s", p[ans].type.Car.brand);
            printf("\nEl Numero de serie del carro: %s", p[ans].type.Car.serialNumber);
            printf("\nEl anho del carro es: %s", p[ans].type.Car.year);
        }
        if(policyType[ans] == 4){
            printf("\nSu poliza de Vida: \n");
            printf("\nNombre del beneficiario: %s", p[ans].type.Life.beneficiary.name);
            printf("\nEl apellido del beneficiario es: %s", p[ans].type.Life.beneficiary.lastname);
            printf("\nAnhos del beneficiario: %d", p[ans].type.Life.beneficiary.age);
            printf("\nNumero de contacto del beneficiario: %s", p[ans].type.Life.beneficiary.contactPhone);
            printf("\nCorreo electronico del beneficiario: %s", p[ans].type.Life.beneficiary.contactMail);
            printf("\nCumpleanhos del beneficiario: %d/%s/%d", p[ans].type.Life.beneficiary.birth.day,p[ans].type.Life.beneficiary.birth.month,p[ans].type.Life.beneficiary.birth.year);

            printf("\nCiudad de residencia del beneficiario: %s", p[ans].type.Life.beneficiary.addres.city);
            printf("\nPais de residencia del beneficiario: %s", p[ans].type.Life.beneficiary.addres.country);
            printf("\nEstado de residencia del beneficiario: %s", p[ans].type.Life.beneficiary.addres.state);

            printf("\nDomicilio de residencia del beneficiario: %s num. #%s", p[ans].type.Life.beneficiary.addres.street,p[ans].type.Life.beneficiary.addres.streetNumber);
    
        }

    }
    else{
        printf("No es valida esta opcion");
    }
}

void datashow(struct policy *p , int *id , int *policyType ){
    int ans;
    printf("\nIngrese el folio a consultar: ");
    scanf("%d",&ans);
    if(policyType[ans] == 0){
        printf("Este folio hasido removido exitosamente!");
    }
    else{
        if(policyType[ans] == 1){
            int mod =0;

            printf("\nQue elemento desea modificar? \n");
            printf("\n1.Nombre de la poliza\n2.Apellido de la poliza\n3.Numero de contacto de la poliza\n4.Correo Electronico de la poliza\n5.Dirrecion del duenho de la        poliza");
            printf("\n6.Ciudad de residencia del duenho de la poliza\n7.Estado de residencia del duenho de la poliza\n8.Pais de residencia del duenho de la poliza");
            printf("\n9.Dirrecion de la poliza asegurada\n10.Ciudad de la poliza Asegurada\n11.Pais de la poliza asegurada\n12.Estado de la poliza asegurada");
            scanf("%d",&mod);
            switch(mod){
                case 1:
                    printf("\nEl nombre bajo el folio es: %s \n", p[ans].policyOwner.name);
                    break;
                case 2:
                    printf("\nEl apellido bajo el folio es: %s \n", p[ans].policyOwner.lastname);
                    break;                
                case 3:
                    printf("\nEl telefono de contacto es: %s \n", p[ans].policyOwner.contactPhone);
                    break;
                case 4:
                    printf("\nEl Email de contacto es: %s \n", p[ans].policyOwner.contactMail);
                    break;
                case 5:
                    printf("\nLa dirrecion del contacto es: %s con el numero %s \n", p[ans].policyOwner.addres.street, p[ans].policyOwner.addres.streetNumber);
                    break;
                case 6:
                    printf("\nEn la ciudad: %s \n", p[ans].policyOwner.addres.city);
                    break;
                case 7:
                    printf("\nEn el estado: %s \n", p[ans].policyOwner.addres.state);
                    break;
                case 8:
                    printf("\nEn el pais: %s \n", p[ans].policyOwner.addres.country);
                    break;
                
                case 9:
                    printf("\nLa dirrecion de la poliza es: %s num. #%s \n", *p[ans].type.Buissnes.addresInsured.street, p[ans].type.Buissnes.addresInsured.streetNumber);
                    break;
                
                case 10:
                    printf("\nLa ciudad es:: %s \n", p[ans].type.Buissnes.addresInsured.city);
                    break;
                case 11:
                    printf("\nEn el pais: %s \n", p[ans].type.Buissnes.addresInsured.country);
                    break;
                case 12:
                    printf("\nEn el estado: %s \n", p[ans].type.Buissnes.addresInsured.state);
                    break;
                default:
                    break;
            }
        }
        if(policyType[ans] == 2){
            printf("\nSu poliza de Vivienda: \n");
            int mod = 0;
            printf("\nQue elemento desea modificar? \n");
            printf("\n1.Nombre de la poliza\n2.Apellido de la poliza\n3.Numero de contacto de la poliza\n4.Correo Electronico de la poliza\n5.Dirrecion del duenho de la poliza");
            printf("\n6.Ciudad de residencia del duenho de la poliza\n7.Estado de residencia del duenho de la poliza\n8.Pais de residencia del duenho de la poliza");
            printf("\n9.Dirrecion de la poliza asegurada\n10.Ciudad de la poliza Asegurada\n11.Pais de la poliza asegurada\n12.Estado de la poliza asegurada");

            scanf("%d",&mod);
            switch(mod){
                case 1:
                    printf("\nEl nombre bajo el folio es: %s \n", p[ans].policyOwner.name);
                    break;
                case 2:
                    printf("\nEl apellido bajo el folio es: %s \n", p[ans].policyOwner.lastname);
                    break;                
                case 3:
                    printf("\nEl telefono de contacto es: %s \n", p[ans].policyOwner.contactPhone);
                    break;
                case 4:
                    printf("\nEl Email de contacto es: %s \n", p[ans].policyOwner.contactMail);
                    break;
                case 5:
                    printf("\nLa dirrecion del contacto es: %s con el numero %s \n", p[ans].policyOwner.addres.street, p[ans].policyOwner.addres.streetNumber);
                    break;
                case 6:
                    printf("\nEn la ciudad: %s \n", p[ans].policyOwner.addres.city);
                    break;
                case 7:
                    printf("\nEn el estado: %s \n", p[ans].policyOwner.addres.state);
                    break;
                case 8:
                    printf("\nEn el pais: %s \n", p[ans].policyOwner.addres.country);
                    break;
                case 9:
                    printf("\nLa dirrecion de la poliza es: %s num. #%s \n", p[ans].type.Home.addresInsured.street,p[ans].type.Home.addresInsured.streetNumber);
                    break;
                case 10:
                    printf("\nLa ciudad es:: %s \n", p[ans].type.Home.addresInsured.city);
                    break;
                case 11:
                    printf("\nEn el estado: %s \n", p[ans].type.Home.addresInsured.state);
                    break;
                case 12:
                    printf("\nEn el pais: %s \n", p[ans].type.Home.addresInsured.country);
                    break;
            }
        }
        if (policyType[ans] == 3){
            printf("\nSu poliza de carro: \n");
            int mod = 0;
            printf("\nQue elemento desea modificar? \n");
            printf("\n1.Nombre de la poliza\n2.Apellido de la poliza\n3.Numero de contacto de la poliza\n4.Correo Electronico de la poliza\n5.Dirrecion del duenho de la poliza");
            printf("\n6.Ciudad de residencia del duenho de la poliza\n7.Estado de residencia del duenho de la poliza\n8.Pais de residencia del duenho de la poliza");
            printf("\n9.Modelo del carro\n10.Marca del auto\n11.Numero de serie\n12.Anho del carro\n");
            scanf(">>%d",&mod);
            switch(mod){
                case 1:
                    printf("\nEl nombre bajo el folio es: %s \n", p[ans].policyOwner.name);
                    break;
                case 2:
                    printf("\nEl apellido bajo el folio es: %s \n", p[ans].policyOwner.lastname);
                    break;                
                case 3:
                    printf("\nEl telefono de contacto es: %s \n", p[ans].policyOwner.contactPhone);
                    break;
                case 4:
                    printf("\nEl Email de contacto es: %s \n", p[ans].policyOwner.contactMail);
                    break;
                case 5:
                    printf("\nLa dirrecion del contacto es: %s con el numero %s \n", p[ans].policyOwner.addres.street, p[ans].policyOwner.addres.streetNumber);
                    break;
                case 6:
                    printf("\nEn la ciudad: %s \n", p[ans].policyOwner.addres.city);
                    break;
                case 7:
                    printf("\nEn el estado: %s \n", p[ans].policyOwner.addres.state);
                    break;
                case 8:
                    printf("\nEn el pais: %s \n", p[ans].policyOwner.addres.country);
                    break;
                case 9:
                    printf("\nEl modelo del carro es: %s", p[ans].type.Car.model);
                    break;
                case 10:
                    printf("\nLa marca del auto es: %s", p[ans].type.Car.brand);
                    break;
                case 11:
                    printf("\nEl Numero de serie del carro: %s", p[ans].type.Car.serialNumber);
                    break;
                case 12:
                    printf("\nEl anho del carro es: %s", p[ans].type.Car.year);
                    break;
            }
  
        }
        if(policyType[ans] == 4 ){
            int mod = 0;
            printf("\nSu poliza de Vida: \n");
            printf("\nQue elemento desea modificar? \n");
            printf("\n9.Nombre del Beficiario\n10.Apellido del beneficiario\n11.Anhos del beneficiario\n12.Numero de contacto del beneficiario");
            printf("\n13.Correo Electronico del beneficiario\n14.Cumpleanhos del beneficiario\n15.Ciudad de residencia del beneficiario\n16.Pais de residencia del beneficiario");
            printf("\n17.Estado de residencia del Beficiario\n19.Domicilio de residencia del beneficiario\n");
            printf("\n1.Nombre de la poliza\n2.Apellido de la poliza\n3.Numero de contacto de la poliza\n4.Correo Electronico de la poliza\n5.Dirrecion del duenho de la poliza");
            printf("\n6.Ciudad de residencia del duenho de la poliza\n7.Estado de residencia del duenho de la poliza\n8.Pais de residencia del duenho de la poliza");
            printf("\n9.Modelo del carro\n10.Marca del auto\n11.Numero de serie\n12.Anho del carro\n");
            scanf(">>%d",&mod);
            switch(mod){
                case 1:
                    printf("\nEl nombre bajo el folio es: %s \n", p[ans].policyOwner.name);
                    break;
                case 2:
                    printf("\nEl apellido bajo el folio es: %s \n", p[ans].policyOwner.lastname);
                    break;                
                case 3:
                    printf("\nEl telefono de contacto es: %s \n", p[ans].policyOwner.contactPhone);
                    break;
                case 4:
                    printf("\nEl Email de contacto es: %s \n", p[ans].policyOwner.contactMail);
                    break;
                case 5:
                    printf("\nLa dirrecion del contacto es: %s con el numero %s \n", p[ans].policyOwner.addres.street, p[ans].policyOwner.addres.streetNumber);
                    break;
                case 6:
                    printf("\nEn la ciudad: %s \n", p[ans].policyOwner.addres.city);
                    break;
                case 7:
                    printf("\nEn el estado: %s \n", p[ans].policyOwner.addres.state);
                    break;
                case 8:
                    printf("\nEn el pais: %s \n", p[ans].policyOwner.addres.country);
                    break;
                case 9:
                    printf("\nNombre del beneficiario: %s", p[ans].type.Life.beneficiary.name);
                    break;
                case 10:
                    printf("\nEl apellido del beneficiario es: %s", p[ans].type.Life.beneficiary.lastname);
                    break;
                case 11:
                    printf("\nAnhos del beneficiario: %d", p[ans].type.Life.beneficiary.age);
                    break;
                case 12:
                    printf("\nNumero de contacto del beneficiario: %s", p[ans].type.Life.beneficiary.contactPhone);
                    break;
                case 13:
                    printf("\nCorreo electronico del beneficiario: %s", p[ans].type.Life.beneficiary.contactMail);
                    break;
                case 14:
                    printf("\nCumpleanhos del beneficiario: %d/%s/%d", p[ans].type.Life.beneficiary.birth.day,p[ans].type.Life.beneficiary.birth.month,p[ans].type.Life.beneficiary.birth.year);
                    break;
                case 15:
                    printf("\nCiudad de residencia del beneficiario: %s", p[ans].type.Life.beneficiary.addres.city);
                    break;
                case 16:
                    printf("\nPais de residencia del beneficiario: %s", p[ans].type.Life.beneficiary.addres.country);
                    break;
                case 17:
                    printf("\nEstado de residencia del beneficiario: %s", p[ans].type.Life.beneficiary.addres.state);
                    break;
                case 18:
                    printf("\nDomicilio de residencia del beneficiario: %s num. #%s", p[ans].type.Life.beneficiary.addres.street,p[ans].type.Life.beneficiary.addres.streetNumber);
                    break;
            }
        }
    }
}



void edit(struct policy *p , int *id , int *policyType ){
    int ans;
    printf("\nIngrese el folio a modificar: ");
    scanf("%d",&ans);
    if(policyType[ans] == 0){
        printf("Este folio No existe!");
    }
    else{
        if(policyType[ans] == 1){
            int mod =0, edit = 0;
            printf("\nQue elemento desea modificar? \n");
            printf("\n1.Nombre de la poliza\n2.Apellido de la poliza\n3.Numero de contacto de la poliza\n4.Correo Electronico de la poliza\n5.Dirrecion del duenho de la        poliza");
            printf("\n6.Ciudad de residencia del duenho de la poliza\n7.Estado de residencia del duenho de la poliza\n8.Pais de residencia del duenho de la poliza");
            printf("\n9.Dirrecion de la poliza asegurada\n10.Ciudad de la poliza Asegurada\n11.Pais de la poliza asegurada\n12.Estado de la poliza asegurada");
            scanf("%d",&mod);
            switch(mod){
                case 1:
                    printf("\nEl nombre bajo el folio es: %s \n", p[ans].policyOwner.name);

                    break;
                case 2:
                    printf("\nEl apellido bajo el folio es: %s \n", p[ans].policyOwner.lastname);
                    break;                
                case 3:
                    printf("\nEl telefono de contacto es: %s \n", p[ans].policyOwner.contactPhone);
                    break;
                case 4:
                    printf("\nEl Email de contacto es: %s \n", p[ans].policyOwner.contactMail);
                    break;
                case 5:
                    printf("\nLa dirrecion del contacto es: %s con el numero %s \n", p[ans].policyOwner.addres.street, p[ans].policyOwner.addres.streetNumber);
                    break;
                case 6:
                    printf("\nEn la ciudad: %s \n", p[ans].policyOwner.addres.city);
                    break;
                case 7:
                    printf("\nEn el estado: %s \n", p[ans].policyOwner.addres.state);
                    break;
                case 8:
                    printf("\nEn el pais: %s \n", p[ans].policyOwner.addres.country);
                    break;
                
                case 9:
                    printf("\nLa dirrecion de la poliza es: %s num. #%s \n", *p[ans].type.Buissnes.addresInsured.street, p[ans].type.Buissnes.addresInsured.streetNumber);
                    break;
                
                case 10:
                    printf("\nLa ciudad es:: %s \n", p[ans].type.Buissnes.addresInsured.city);
                    break;
                case 11:
                    printf("\nEn el pais: %s \n", p[ans].type.Buissnes.addresInsured.country);
                    break;
                case 12:
                    printf("\nEn el estado: %s \n", p[ans].type.Buissnes.addresInsured.state);
                    break;
                default:
                    break;
            }
        }
        if(policyType[ans] == 2){
            printf("\nSu poliza de Vivienda: \n");
            int mod = 0;
            printf("\nQue elemento desea modificar? \n");
            printf("\n1.Nombre de la poliza\n2.Apellido de la poliza\n3.Numero de contacto de la poliza\n4.Correo Electronico de la poliza\n5.Dirrecion del duenho de la poliza");
            printf("\n6.Ciudad de residencia del duenho de la poliza\n7.Estado de residencia del duenho de la poliza\n8.Pais de residencia del duenho de la poliza");
            printf("\n9.Dirrecion de la poliza asegurada\n10.Ciudad de la poliza Asegurada\n11.Pais de la poliza asegurada\n12.Estado de la poliza asegurada");

            scanf("%d",&mod);
            switch(mod){
                case 1:
                    printf("\nEl nombre bajo el folio es: %s \n", p[ans].policyOwner.name);
                    break;
                case 2:
                    printf("\nEl apellido bajo el folio es: %s \n", p[ans].policyOwner.lastname);
                    break;                
                case 3:
                    printf("\nEl telefono de contacto es: %s \n", p[ans].policyOwner.contactPhone);
                    break;
                case 4:
                    printf("\nEl Email de contacto es: %s \n", p[ans].policyOwner.contactMail);
                    break;
                case 5:
                    printf("\nLa dirrecion del contacto es: %s con el numero %s \n", p[ans].policyOwner.addres.street, p[ans].policyOwner.addres.streetNumber);
                    break;
                case 6:
                    printf("\nEn la ciudad: %s \n", p[ans].policyOwner.addres.city);
                    break;
                case 7:
                    printf("\nEn el estado: %s \n", p[ans].policyOwner.addres.state);
                    break;
                case 8:
                    printf("\nEn el pais: %s \n", p[ans].policyOwner.addres.country);
                    break;
                case 9:
                    printf("\nLa dirrecion de la poliza es: %s num. #%s \n", p[ans].type.Home.addresInsured.street,p[ans].type.Home.addresInsured.streetNumber);
                    break;
                case 10:
                    printf("\nLa ciudad es:: %s \n", p[ans].type.Home.addresInsured.city);
                    break;
                case 11:
                    printf("\nEn el estado: %s \n", p[ans].type.Home.addresInsured.state);
                    break;
                case 12:
                    printf("\nEn el pais: %s \n", p[ans].type.Home.addresInsured.country);
                    break;
            }
        }
        if (policyType[ans] == 3){
            printf("\nSu poliza de carro: \n");
            int mod = 0;
            printf("\nQue elemento desea modificar? \n");
            printf("\n1.Nombre de la poliza\n2.Apellido de la poliza\n3.Numero de contacto de la poliza\n4.Correo Electronico de la poliza\n5.Dirrecion del duenho de la poliza");
            printf("\n6.Ciudad de residencia del duenho de la poliza\n7.Estado de residencia del duenho de la poliza\n8.Pais de residencia del duenho de la poliza");
            printf("\n9.Modelo del carro\n10.Marca del auto\n11.Numero de serie\n12.Anho del carro\n");
            scanf(">>%d",&mod);
            switch(mod){
                case 1:
                    printf("\nEl nombre bajo el folio es: %s \n", p[ans].policyOwner.name);
                    break;
                case 2:
                    printf("\nEl apellido bajo el folio es: %s \n", p[ans].policyOwner.lastname);
                    break;                
                case 3:
                    printf("\nEl telefono de contacto es: %s \n", p[ans].policyOwner.contactPhone);
                    break;
                case 4:
                    printf("\nEl Email de contacto es: %s \n", p[ans].policyOwner.contactMail);
                    break;
                case 5:
                    printf("\nLa dirrecion del contacto es: %s con el numero %s \n", p[ans].policyOwner.addres.street, p[ans].policyOwner.addres.streetNumber);
                    break;
                case 6:
                    printf("\nEn la ciudad: %s \n", p[ans].policyOwner.addres.city);
                    break;
                case 7:
                    printf("\nEn el estado: %s \n", p[ans].policyOwner.addres.state);
                    break;
                case 8:
                    printf("\nEn el pais: %s \n", p[ans].policyOwner.addres.country);
                    break;
                case 9:
                    printf("\nEl modelo del carro es: %s", p[ans].type.Car.model);
                    break;
                case 10:
                    printf("\nLa marca del auto es: %s", p[ans].type.Car.brand);
                    break;
                case 11:
                    printf("\nEl Numero de serie del carro: %s", p[ans].type.Car.serialNumber);
                    break;
                case 12:
                    printf("\nEl anho del carro es: %s", p[ans].type.Car.year);
                    break;
            }
  
        }
        if(policyType[ans] == 4 ){
            int mod = 0;
            printf("\nSu poliza de Vida: \n");
            printf("\nQue elemento desea modificar? \n");
            printf("\n9.Nombre del Beficiario\n10.Apellido del beneficiario\n11.Anhos del beneficiario\n12.Numero de contacto del beneficiario");
            printf("\n13.Correo Electronico del beneficiario\n14.Cumpleanhos del beneficiario\n15.Ciudad de residencia del beneficiario\n16.Pais de residencia del beneficiario");
            printf("\n17.Estado de residencia del Beficiario\n19.Domicilio de residencia del beneficiario\n");
            printf("\n1.Nombre de la poliza\n2.Apellido de la poliza\n3.Numero de contacto de la poliza\n4.Correo Electronico de la poliza\n5.Dirrecion del duenho de la poliza");
            printf("\n6.Ciudad de residencia del duenho de la poliza\n7.Estado de residencia del duenho de la poliza\n8.Pais de residencia del duenho de la poliza");
            printf("\n9.Modelo del carro\n10.Marca del auto\n11.Numero de serie\n12.Anho del carro\n");
            scanf(">>%d",&mod);
            switch(mod){
                case 1:
                    printf("\nEl nombre bajo el folio es: %s \n", p[ans].policyOwner.name);
                    break;
                case 2:
                    printf("\nEl apellido bajo el folio es: %s \n", p[ans].policyOwner.lastname);
                    break;                
                case 3:
                    printf("\nEl telefono de contacto es: %s \n", p[ans].policyOwner.contactPhone);
                    break;
                case 4:
                    printf("\nEl Email de contacto es: %s \n", p[ans].policyOwner.contactMail);
                    break;
                case 5:
                    printf("\nLa dirrecion del contacto es: %s con el numero %s \n", p[ans].policyOwner.addres.street, p[ans].policyOwner.addres.streetNumber);
                    break;
                case 6:
                    printf("\nEn la ciudad: %s \n", p[ans].policyOwner.addres.city);
                    break;
                case 7:
                    printf("\nEn el estado: %s \n", p[ans].policyOwner.addres.state);
                    break;
                case 8:
                    printf("\nEn el pais: %s \n", p[ans].policyOwner.addres.country);
                    break;
                case 9:
                    printf("\nNombre del beneficiario: %s", p[ans].type.Life.beneficiary.name);
                    break;
                case 10:
                    printf("\nEl apellido del beneficiario es: %s", p[ans].type.Life.beneficiary.lastname);
                    break;
                case 11:
                    printf("\nAnhos del beneficiario: %d", p[ans].type.Life.beneficiary.age);
                    break;
                case 12:
                    printf("\nNumero de contacto del beneficiario: %s", p[ans].type.Life.beneficiary.contactPhone);
                    break;
                case 13:
                    printf("\nCorreo electronico del beneficiario: %s", p[ans].type.Life.beneficiary.contactMail);
                    break;
                case 14:
                    printf("\nCumpleanhos del beneficiario: %d/%s/%d", p[ans].type.Life.beneficiary.birth.day,p[ans].type.Life.beneficiary.birth.month,p[ans].type.Life.beneficiary.birth.year);
                    break;
                case 15:
                    printf("\nCiudad de residencia del beneficiario: %s", p[ans].type.Life.beneficiary.addres.city);
                    break;
                case 16:
                    printf("\nPais de residencia del beneficiario: %s", p[ans].type.Life.beneficiary.addres.country);
                    break;
                case 17:
                    printf("\nEstado de residencia del beneficiario: %s", p[ans].type.Life.beneficiary.addres.state);
                    break;
                case 18:
                    printf("\nDomicilio de residencia del beneficiario: %s num. #%s", p[ans].type.Life.beneficiary.addres.street,p[ans].type.Life.beneficiary.addres.streetNumber);
                    break;
            }
        }
    }




    }    
}

/*
void search(){

}

*/
void delete(int *policyType){
    int ans = 0;
    printf("\nDiguite el numero de folio que dese eliminar: ");
    scanf("%d",&ans);
    if(policyType[ans]==0){
        printf("Este folio ya no existe.");
    }else{
        policyType[ans]=0;
        printf("\nEl folio ha sido eliminado con un exito del 100!");
    }

}

int sort(struct policy *p, int beging, int end, int search){
    int half =(beging + end)/2;
    if(search == half){
        return half;
    }
    else if(search<p[half].id){
        sort(p,half+1,end,beging);
    }
    else if(search>p[half].id){
        sort(p,half-1,end,beging);
    }else{
        return -1;
    }

}

int policytypedef (){
    printf("Selecione un tipo de poliza:\n");
    printf(" 1.Automotris\n 2.Vida\n 3.Negocios\n 4.Casa\n");
    int ans = 0;
    int flag = 0;
    printf("---> ");
    scanf("%d",&ans);
    while(flag == 0){
        if(ans >=1 && ans <= 4){
            flag++;
            return ans;
        }else{
            printf("ERROR 1\n");
        }
    }
}

void add(struct policy *p, int *id,int policyType){
    printf("---AGREGAR POLIZA---");
    printf("introduce el nombre del dueño de la poliza");
    scanf("%s", p[*id].policyOwner.name);
    printf("introduce el apellido del dueño de la poliza");
    scanf("%s", p[*id].policyOwner.lastname);
    printf("introduce el numero de telefono del dueño de la poliza");
    scanf("%s", p[*id].policyOwner.contactPhone);
    printf("introduce el correo electronico del dueño de la poliza");
    scanf("%s", p[*id].policyOwner.contactMail);
    printf("introduce la dirección del dueño");
    printf("pais");
    scanf("%s", p[*id].policyOwner.addres.country);
    printf("estado");
    scanf("%s", p[*id].policyOwner.addres.state);
    printf("ciudad");
    scanf("%s", p[*id].policyOwner.addres.city);
    printf("calle");
    scanf("%s", p[*id].policyOwner.addres.street);
    printf("numero exterior");
    scanf("%s", p[*id].policyOwner.addres.streetNumber);
    printf("introduce el precio de la poliza");
    scanf("%f", &p[*id].genaralData.price);
    printf("introduce el deducible de la poliza");
    scanf("%f", &p[*id].genaralData.deductible);
    printf("introduce la suma asegurada de la poliza");
    scanf("%f", &p[*id].genaralData.sumAssured);
    printf("introduce el tipo de covertura de la poliza");
    scanf("%s", p[*id].genaralData.coverage);
    printf("introduce la fecha de vigencia de la poliza");
    printf("año");
    scanf("%s", p[*id].genaralData.vigency.year);
    printf("mes");
    scanf("%s", p[*id].genaralData.vigency.month);
    printf("dia");
    scanf("%s", p[*id].genaralData.vigency.day);

    switch (policyType)
    {
    case 1:
        printf("introduzca la dirección asegurada\n");
        printf("pais\n");
        scanf("%s", p[*id].policyOwner.addres.country);
        printf("estado\n");
        scanf("%s", p[*id].policyOwner.addres.state);
        printf("ciudad\n");
        scanf("%s", p[*id].policyOwner.addres.city);
        printf("calle\n");
        scanf("%s", p[*id].policyOwner.addres.street);
        printf("numero exterior\n");
        scanf("%s", p[*id].policyOwner.addres.streetNumber);

        break;
    case 2:
        printf("introduzca la dirección asegurada");
        printf("pais\n");
        scanf("%s", p[*id].policyOwner.addres.country);
        printf("estado\n");
        scanf("%s", p[*id].policyOwner.addres.state);
        printf("ciudad\n");
        scanf("%s", p[*id].policyOwner.addres.city);
        printf("calle\n");
        scanf("%s", p[*id].policyOwner.addres.street);
        printf("numero exterior\n");
        scanf("%s", p[*id].policyOwner.addres.streetNumber);
        break;
    case 3:
    /*
    
    */
        printf("introduzca la marca del carro asegurado\n");
        printf("introduzca el modelo del carro asegurado\n");
        break;

    case 4: // life
        break;
    }

    (*id)++;
}





int menu (struct policy *po, int *it){
    printf("Bienvenido al sistema de polizas\n");
    printf("Escoja una opción:\n");
    printf("1.Agregar\n 2.Eliminar\n 3.Buscar\n 4.Editar\n 5.Mostar algun dato en especifico");
    printf("6.Mostrar todos los datos de la poliza\n 7.Para Salir.\n");
    printf("---> ");
    int ans = 0;
    scanf("%d",&ans);
    int definition;
    int exit = 0;
    while (!exit){
        switch (ans){
            case 1:
                definition = policytypedef();
                if (definition >= 1 || definition <= 4){
                    // add(po,&it, definition);
                    ans++;
                    add(po,&it, definition);
                }else{
                    printf("Error 0");
                }
                
                break;
            /*case 2: 
                delete();
                break;
            case 3:
                search();
                break;
            case 4: 
                edit();
                break;
            case 5:
                datashow();
                break;
            case 6: 
                datashowall();
                break; */
            case 7: 
                printf("Gracias por escojernos :)");
                ++exit;
        }
    }
}


int main(){
    struct policy p[10];
    int size = 10;
    int i = 0 ;
    menu(p,&i);
    ++i;
    
    

}


