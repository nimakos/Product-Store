//#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>


struct stats                //Δημιουργία δομής τριών χαρακτηριστικών
{
	char name[40];
	float price;
	float stock;
};

struct stats product[20] = {      // Πέρασμα 20 προϊόντων. Το όνομα η τιμή, και το διαθέσιμο απόθεμα
	{ "Couch",200,5 },
	{ "Table",100,6 },
	{ "Kitchen",400,2 },
	{ "Fridge",250,1 },
	{ "Machine",346,7 },
	{ "Closet",134,2 },
	{ "Desk",35,20 },
	{ "Library",60,25 },
	{ "Bed",100,40 },
	{ "Bathtub",450,6 },
	{ "Frame",30,15 },
	{ "commode",40,18 },
	{ "Clima",500,5 },
	{ "TV",600,7 },
	{ "Coffee",20,15 },
	{ "Oven",300,3 },
	{ "Dehumin",350,15 },
	{ "Dishes",50,17 },
	{ "Besom",70,37 },
	{ "Dryer",300,27 }
};



void min_product()                      //Συνάρτηση εύρεσης προιόντος με το λιγότερο απόθεμα
{
	int i;
	float min = product[0].stock;       //αρχικοποιούμε την μεταβλητη min να πάρει την τιμή του 1 προιόντος για να έχουμε μέτρο σύγκρισης
    printf("------The product with fewer stock--------------\n");
	for (i = 0; i<20; i++)
	{
		if (product[i].stock < min)    //όταν μια τιμή βρεθεί μικρότερη της min
			min = product[i].stock;    //βάλε στην μεταβλητή min την τιμή αυτή
	}

	for (i = 0; i<20; i++)              //Κάνουμε μια δεύτερη λούπα για την εκτύπωση
	{
		if (min == product[i].stock)    //εφ΄όσον έχει βρεθεί η τιμή της min
			printf("%s\n", product[i].name);
	}

}

void less_than()       //Συνάρτηση εύρεσης προιόντων με το πολύ 10 κομμάτια απόθεμα
{
	int i;
    printf("---------The products with stock less than 10 pieces-----------\n");
	for (i = 0; i<20; i++)
	{
		if (product[i].stock <= 10)     //Εάν το απόθεμα είναι μικρότερο του 10
			printf("%s\t\n", product[i].name);  //τύπωσε το όνομα αυτών των προιόντων
	}
}

void sum_price()        //Συνάρτηση έυρεσης συνολικής αξίας εμπορευματος
{
	int i;
	float sum = 0;  //Αρχικοποιούμε την μεταβλητή sum για να κάνουμε το άθροισμα
	printf("---------Total price of cargo-----------\n");
	for (i = 0; i<20; i++)
	{
		sum += product[i].price*product[i].stock; //Πολ/ζουμε την τιμή κάθε προιόντος με το απόθεμα του
	}
	printf("Max price of cargo is: %.f EURO\n", sum); //Τυπώνουμε το αποτέλεσμα
}

void percentage()        //Συνάρτηση εύρεσης ποσοστου εμπορευματων λιγότερο από 15 κομμάτια
{
	int i;
	float percentage ;
	float sum1=0.0, sum=0.0;
	printf("---------The percentage of cargo with stock less than 15 pieces:---------\n");
	for (i = 0; i<20; i++)
	{
		sum++; //Μετρητής αθροίσματος συνόλου προΙόντων
	}

	for (i = 0; i<20; i++)
	{
	    if (product[i].stock<15)
	    {
	        sum1++; //Μετρητής αθροίσματος προϊόντων με απόθεμα κάτω από 15 απόθεμα
	    }
	}
percentage  = (sum1) / (sum) * 100; //Στη μεταβήτη percentage καταχωρείται τα προιόντα με απόθεμα μικροτερο του 15 δια το σύνολο του εμπορεύματος επι 100
printf("The percentage  of cargo is:\t%.f percent\n", percentage); //Τύπωμα του ποσοστού των εμπορευμάτων
}

void average_price0() //Συνάρτηση έυρεσης μέσης τιμής απο τις τιμές των προιοντων με απόθεμα μεγαλύτερο του 20
{
	int i;
	int counter = 0;
	float sum = 0, average;
    printf("---------Average Price of prices of products with stock larger than 20------\n");
	for (i = 0; i<20; i++)
	{
		if (product[i].stock>20)    //Εαν το απόθεμα είναι μεγαλύτερο του 20
		{
			sum += product[i].price;  //Αθροίζουμε τις τιμές των προιόντων
			counter++;      //Μέτρησε τον αριθμό των προιόντων
		}
	}
	average = sum / counter;    //Στη μεταβλητή average καταχωρείται το άθροισμα δια τονη αριθμό των επαναλήψεων
	printf("Average price is: %.2f EURO\n", average); //Τύπωση
}


void rise() //Συνάρτηση προσάυξησης προιοντων με τιμη 10-75€ και 15 κομμάτια
{
	int i;
    printf("---------Product price increased by 20 percent------\n");
	for (i = 0; i < 20; i++)
	{   //Εαν η τιμή των προιοντων ειναι μεγαλυτερη η ιση του 10 και τιμη μικροτερη η ιση του 75 και το απόθεμα είναι 15
		if (product[i].price >= 10 && product[i].price <= 75 && product[i].stock == 15)
		{
			product[i].price = 1.2*product[i].price;  //Γίνεται η προσάυξηση των προιόντων
			printf("%s\t %.f EURO\n", product[i].name, product[i].price); //Τύπωμα των προιοντων
		}
	}
}


void average_price() //Συνάρτηση ευρεσης προιόντων που ξεπερνουν σε τιμή τα 3/5 της μέσης τιμής των προιόντων της αποθήκης
{
	int i;
	float sum = 0, average, mt;
	printf("---------Products that surpass the 3/5 of average price of products------\n");
	for (i = 0; i < 20; i++)
	{
		sum += product[i].price; //Αθροίζουμε τις τιμές των προιόντων
	}
	average = sum / 20; //Υπολογίζουμε την μέση τιμή των προιόντων της αποθήκης
	mt = average*(3) / 5;   //Στη μεταβλητή mt καταχωρίζονται τα τρια πέμπτα της μέσης τιμής των προιόντων
	for (i = 0; i < 20; i++)
	{
		if (product[i].price > mt) //Εαν η τιμή των προιόντων ξεπερναει τη μεταβλητή mt
		{
			printf("%s\t%.f EURO\n", product[i].name, product[i].price);  // Τύπωσε τα προιοντα
		}
	}
}


void bubble_short() //Συνάρτηση ταξινόμησης κατα τιμή και στη συνέχεια κατ αλφαβητική σειρά
{
	FILE *fp1;  //Το αρχείο που θα χρσιμοποιήσουμε για να αποθηκεύσουμε τις τιμές
	fp1 = fopen("sch.txt", "w");    //Ανοίγουμε το αρχείο και κάνουμε εγγραφή σε αυτό
	int i, j;
	float x, z;
	char y[20]; // Αρχικοποιούμε ενα προσωρινό πίνακα για να πάρει τιμές
    printf("---------Short by price and by name------\n");
	for (i = 0; i < 19; i++)
	{
		for (j = i+1; j<20; j++)//εξετάζουμε μια προς μια τις τιμες του πινακα με τις δύο λούπες bubble short
		{
			if (product[i].price > product[j].price) // εαν η τιμή του προηγουμενου στοιχειου του πινακα είναι μεγαλύτερη απο την τιμή του επόμενου στοιχείου
			{   //ταξινόμησε κατά άυξουσα τιμή
				x = product[i].price; // αποθήκευσε την τιμή του προηγούμενου στοιχείου στην προσωρινη μεταβλητη x
				product[i].price = product[j].price; // αποθηκευσε την τιμη του επόμενου στοιχείου στην θέση του προηγούμενου στοιχείου
				product[j].price = x; // και στην θέση του επόμνενου στοιχείου βάλε την την τιμή της προσωρινης μεταβλητης x
                //ταξινόμησε κατά όνομα προιόντος
				strcpy(y, product[i].name); //αντέγραψε το όνομα του προιοντος στον προσωρινό πίνακα y
				strcpy(product[i].name, product[j].name);// αντέγραψε το όνομα του επόμενου στοιχείου [j] στη θέση του ονόματος του προηγούμενου στοιχείου [i]
				strcpy(product[j].name, y);//και στη θέση του επόμενου στοιχείου [j] αντέγραψε την τιμή του προσωρινού πίνακα y
                //Ταξινόμησε και κατά το απόθεμα
				z = product[i].stock;
				product[i].stock = product[j].stock;
				product[j].stock = z;
			}
		}
	}
	for (i = 0; i < 4; i++)
	{
		for (j = i+1; j < 5; j++)//γινονται πάλι δυο λούπες για ταξινόμηση με βάση τα 5 ποιο φτηνα προιόντα
		{
			if (strcmp(product[i].name, product[j].name)> 0) //εαν η τιμή του ονόματος του προηγουμενου στοιχειου του πινακα είναι μεγαλύτερη απο την τιμή του ονόματος του επόμενου στοιχείου
			{   //ταξινόμησε κατά άυξουσα τιμή
				x = product[i].price;
				product[i].price = product[j].price;
				product[j].price = x;
                //ταξινόμησε κατά όνομα προιόντος
				strcpy(y, product[i].name);
				strcpy(product[i].name, product[j].name);
				strcpy(product[j].name, y);
                //Ταξινόμησε κατά το απόθεμα
				z = product[i].stock;
				product[i].stock = product[j].stock;
				product[j].stock = z;
			}
		}
	}

	for (i = 0; i < 5; i++) //μια τελευταία λούπα για το τύπωμα
	{
		printf("%s\t%.f\n", product[i].name, product[i].price); // τύπωση των τιμών στην οθόνη
		fprintf(fp1, "\n%s\t %.f\n", product[i].name, product[i].price); // τύπωση των τιμών στο αρχείο
	}
	fclose(fp1); // κλείσε το αρχείο
}


void stock_safety() //Συνάρτηση αποθέματος ασφαλείας

{
	int i;
	int counter = 0, stock_safe; //Αρχικοποιούμε τις μεταβλητές μας
	float x;
    printf("--------------Stock Safety-----------\n");
	printf("Give stock Safety\n");
	scanf("%d", &stock_safe);      //Διάβασε το απόθεμα ασφαλείας απο το χρήστη και αποθηκευσέ το στην διευθυνση μεταβλητης της stock_safe

	for (i = 0; i < 20; i++)
	{
		if (stock_safe > product[i].stock) //Εαν η τιμή που έδωσε ο χρήστης είναι μεγαλύτερη απο αυτό που έχουμε στην αποθήκη μας
		{
			counter++;  //μέτρησε τον αριθμό των προιοντων
			x = stock_safe - product[i].stock; //Και αποθήκευσε στη μεταβλητη x τη διαφορά για το κάθε προιον
			printf("%s\tProduct Stock:\t%.f\tstock Safety order is:  %.f\n",product[i].name, product[i].stock, x); //Εκτύπωσε το κάθε προιον ξεχωριστά
			continue; //όσο ισχύει η συνθήκη συνέχιζε
		}
	}
	printf("\nNumber of products with problem in stock  %d\n", counter); //Εμφανίζει τον αριθμό σε σύνολο των προιοντων που έχουν πρόβλημα

}



int main()
{

    int x;
	while (1)
    {                                 //όσο το input ειναι αλήθεια
		printf("\n1.Product with less Pieces\n"     //κατασκεύαζουμε τη μορφή που θα έχει το menu

                 "2.Products with at most 10 Pieces\n"

                 "3.Sum Price of cargo\n"

                 "4.Percentage of Cargo\n"

                 "5.Average Price of products\n"

                 "6.Increase Price of products by 20 Percent\n"

                 "7.Products that exceeds average price\n"

                 "8.Short by price and by name\n"

                 "9.Safety Stock\n"

                 "0.EXIT\n\n");


		x=getch();    //πάρε τις τιμές για το menu

		switch (x)
           {

		case '1':

			min_product();      //Συνάρτηση εύρεσης προιόντος με το λιγότερο απόθεμα

			break;

		case '2':

			less_than();        //Συνάρτηση εύρεσης προιόντων με το πολύ 10 κομμάτια απόθεμα

			break;

		case '3':

			sum_price();        //Συνάρτηση έυρεσης συνολικής αξίας εμπορευματος

			break;

		case '4':

			percentage();        //Συνάρτηση εύρεσης ποσοστου εμπορευματων λιγότερο από 15 κομμάτια

			break;

		case '5':

			average_price0();   //Συνάρτηση έυρεσης μέσης τιμής απο τις τιμές των προιοντων με απόθεμα μεγαλύτερο του 20

			break;

		case '6':

			rise();             //Συνάρτηση προσάυξησης προιοντων με τιμη 10-75€ και 15 κομμάτια

			break;

		case '7':

			average_price();    //Συνάρτηση ευρεσης προιόντων που ξεπερνουν σε τιμή τα 3/5 της μέσης τιμής των προιόντων της αποθήκης

			break;

		case '8':

			bubble_short();     //Συνάρτηση ταξινόμησης κατα τιμή και στη συνέχεια κατ αλφαβητική σειρά

			break;

		case '9':

			stock_safety();      //Συνάρτηση αποθέματος ασφαλείας

			break;

		case '0':

			printf("\nBye!!!");

			exit(0);

			break;

		default:
            printf("\nWrong Button\n");

            break;
		}
	}
}
