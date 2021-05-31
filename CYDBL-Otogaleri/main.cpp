#include <iostream>
#include <fstream>
//Çift yönlü dairesel baðlý liste uygulamasý

using namespace std;

struct node{
    string plaka, marka;
    int fiyat;
    node *next;
    node *prev;
};

node *head=NULL;

void ekle(string plaka, string marka, int fiyat){
    node *eleman= new node();
    eleman->plaka=plaka;
    eleman->marka=marka;
    eleman->fiyat=fiyat;

    if(head==NULL){
        head=eleman;
        head->next=head;
        head->prev=head;
        cout << head->plaka << " plakali ilk arac otogaleriye eklendi!" << endl;}

    else{
        node *iter=head;
        while(iter->next!=head)
            iter= iter->next;
        iter->next=eleman;
        eleman->next=head;
        eleman->prev=iter;
        head->prev=eleman;
        cout << eleman->plaka << " plakali arac otogaleriye eklendi!" << endl;}
}

void sat(string plaka){

    if(head==NULL){ cout << "Otogaleri bos!" << endl; }

    else if(head->next==head && head->plaka==plaka){
        int satisFiyati=head->fiyat + head->fiyat * 0.1;
        cout << head->plaka << " plakali arac " << satisFiyati << " TL'ye satildi!" << endl;
        delete head;
        head=head->prev=head->next=NULL;    }

    else if(head->next!=head && head->plaka==plaka){
        int satisFiyati=head->fiyat + head->fiyat * 0.1;
        cout << head->plaka << " plakali arac " << satisFiyati << " TL'ye satildi!" << endl;
        node *temp= head->next;
        node *temp2= head->prev;
        delete head;
        head=temp;
        temp2->next=temp;
        temp->prev=temp2;}
    else{
        node *iter=head->next;
        while(iter!=head){
            if(iter->plaka==plaka){
                int satisFiyati=iter->fiyat + iter->fiyat * 0.1;
                cout << iter->plaka << " plakali arac " << satisFiyati << " TL'ye satildi!" << endl;
                node *temp1 = iter->next;
                node *temp2 = iter->prev;
                delete iter;
                temp2->next=temp1;
                temp1->prev=temp2;}
            else{
                cout << plaka << " plakali arac otogaleride bulunamadi!" << endl;
                break;}
            iter=iter->next;


            }}
}

void yazdir(){

    if(head==NULL){ cout << "Otogaleri bos!" << endl; }

    else{
        node *iter=head;
        while(iter->next!=head){
            cout << iter->plaka << " " << iter->marka << " " << iter->fiyat << endl;
            iter=iter->next;}
        cout << iter->plaka << " " << iter->marka << " " << iter->fiyat << endl;
    }
}



int main()
{
    int fiyat, sayi, secim;
    string plaka, marka;
    while(true){
        cout << "\nOTOGALERI UYGULAMASI" << endl;
        cout << "0- Cikis" << endl;
        cout << "1- Arac al" << endl;
        cout << "2- Arac sat" << endl;
        cout << "3- Arac listesi" << endl;
        cout << "4- Arac sayisi" << endl;
        cout << "5- Araclarin toplam ucreti" << endl;
        cout << "6- Araclari dosyaya kaydet" << endl;
        cout << "7- Dosyada kaydindaki araclari getir" << endl;
        cin >> secim;
        switch(secim){
            case 0:
                cout << "Programdan cikis yapiliyor..." << endl;
                return 0;
            case 1:
                cout << "Otoparka alinacak aracin bilgilerini giriniz" << endl;
                cout << "Plaka: "; cin >> plaka;
                cout << "Marka: "; cin >> marka;
                cout << "Fiyat: "; cin >> fiyat;
                ekle(plaka,marka,fiyat);
                break;
            case 2:
                cout << "Otoparktan cikartilacak aracin plakasini giriniz" << endl;
                cout << "Plaka: "; cin >> plaka;
                sat(plaka);
                break;
            case 3:
                cout << "Arac Listesi:" << endl;
                yazdir();
                break;
            /*case 4:
                adet();
                break;
            case 5:
                ucretToplami();
                break;
            case 6:
                dosyayaYaz();
                break;
            case 7:
                dosyadanOku();
                break;*/
            default:
                cout << "Lutfen gecerli bir islem seciniz!" << endl;
                break;}
    }
    return 0;
}
