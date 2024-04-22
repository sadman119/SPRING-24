#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for adding Doctor
struct add_doc
{
  int index;
  char name[30];
  char cell[15];
  int fee;
  char degree[30];
  char category[30];
  int category_no;
  char medical[50];
  char schedule[100];
  int count;
  struct add_doc *next;
};

struct add_doc *top1 = NULL;

// using stack to push doctor information from main function
void
add_doctor (int index, int category_no, char *name, char *cell, int fee,
			char *degree, char *category, char *medical, char *schedule)
{
  struct add_doc *new_doc = malloc (sizeof (struct add_doc));
  if (new_doc == NULL)
	{
	  printf ("Memory allocation failed\n");
	  exit (1);
	}
  new_doc->index = index;
  strcpy (new_doc->name, name);
  strcpy (new_doc->cell, cell);
  new_doc->fee = fee;
  new_doc->category_no = category_no;
  strcpy (new_doc->degree, degree);
  strcpy (new_doc->category, category);
  strcpy (new_doc->medical, medical);
  strcpy (new_doc->schedule, schedule);
  new_doc->count = 0;
  new_doc->next = top1;
  top1 = new_doc;
}

// using stack to push doctor information from admin pannel
void
add_doctor_manually ()
{
  struct add_doc *new_doc = malloc (sizeof (struct add_doc));
  if (new_doc == NULL)
	{
	  printf ("Memory allocation failed\n");
	  exit (1);
	}

  printf ("Enter doctor's index: ");
  scanf ("%d", &new_doc->index);

  printf ("Enter doctor's name: ");
  scanf ("%s", new_doc->name);

  printf ("Enter doctor's cell: ");
  scanf ("%s", new_doc->cell);

  printf ("Enter doctor's fee: ");
  scanf ("%d", &new_doc->fee);

  printf ("Enter doctor's category number: ");
  scanf ("%d", &new_doc->category_no);

  printf ("Enter doctor's degree: ");
  scanf ("%s", new_doc->degree);

  printf ("Enter doctor's category: ");
  scanf ("%s", new_doc->category);

  printf ("Enter doctor's medical: ");
  scanf ("%s", new_doc->medical);

  printf ("Enter doctor's schedule: ");
  scanf ("%s", new_doc->schedule);

  new_doc->count = 0;
  new_doc->next = top1;
  top1 = new_doc;
}

                                                            //User Area To Show The list of Doctors
                                                            //Displaying Doctor Info as per user Choice
void
display_doctors ()
{
  printf ("\nYou have selected Doctor Appointment.\n");
  printf ("Select Category\n");
  printf ("1. Emergency Medicine Physician\n");
  printf ("2. General Practitioner (GP)\n");
  printf ("3. Pediatrician\n");
  printf ("4. Obstetrician/Gynecologist (OB/GYN)\n");
  printf ("5. Cardiologist\n");
  printf ("6. Neurologist\n");
  printf ("7. Endocrinologist\n");
  printf ("8. Gastroenterologist\n");
  printf ("9. Oncologist\n");
  printf ("10. Dermatologist\n");
  int choice;
  printf ("\nEnter your Category Index: ");
  scanf ("%d", &choice);

                                            //searching in the Doctor Stack (Linear Search)
  struct add_doc *ptr;
  ptr = top1;
  printf ("\n");
  while (ptr != NULL)
	{
	  if (ptr->category_no == choice)
		{

		  printf ("------------------------------------------\n");
		  printf ("Index: %d\n", ptr->index);
		  printf ("Name: %s\n", ptr->name);
		  printf ("Cell: %s\n", ptr->cell);
		  printf ("Fee: %d\n", ptr->fee);
		  printf ("Degree: %s\n", ptr->degree);
		  printf ("Category: %s\n", ptr->category);
		  printf ("Medical College: %s\n", ptr->medical);
		  printf ("Schedule: %s\n", ptr->schedule);
		  printf ("\n");
		}
	  ptr = ptr->next;
	}

  int doctorserial;
  printf ("Enter the index of the doctor to select: ");
  scanf ("%d", &doctorserial);
  ptr = top1;
  while (ptr->index != doctorserial)
	{
	  ptr = ptr->next;
	}
  ptr->count++;
  printf ("\nYour serial number is : %d\n", ptr->count);
  printf ("Call for change your appointment time: 01303409319\n");
  printf ("===================================================\n");
}

		                            //Structure for adding test  to our Program
struct add_test
{
  char test_name[30];
  int homeservice;
  int test_index;
  int fees;
  int time;
  int tcount;
  struct add_test *next;
};

struct add_test *top2 = NULL;
								//Creating Stack to add test from main function
void
add_tests (char *test_name, int hservice_index, int test_index, int fees,
		   int time)
{
  struct add_test *new_test =
	(struct add_test *) malloc (sizeof (struct add_test));
  strcpy (new_test->test_name, test_name);
  new_test->homeservice = hservice_index;
  new_test->test_index = test_index;
  new_test->fees = fees;
  new_test->time = time;
  new_test->next = top2;
  new_test->tcount = 0;
  top2 = new_test;
}

                                //Creating Stack to add test from main function
void
add_test_manually ()
{
  struct add_test *new_test = malloc (sizeof (struct add_test));
  if (new_test == NULL)
	{
	  printf ("Memory allocation failed\n");
	  exit (1);
	}

  printf ("Enter test name: ");
  scanf ("%s", new_test->test_name);

  printf ("Enter home service index: ");
  scanf ("%d", &new_test->homeservice);

  printf ("Enter test index: ");
  scanf ("%d", &new_test->test_index);

  printf ("Enter fees: ");
  scanf ("%d", &new_test->fees);

  printf ("Enter time: ");
  scanf ("%d", &new_test->time);

  new_test->tcount = 0;
  new_test->next = top2;
  top2 = new_test;
}

                                                        //display reports
void
test_reports ()
{
  printf ("\nYou Have selected test & Reports\n");
  printf ("\nChoose option from below\n");
  printf ("1. In Centre Sample Collection\n");	//1
  printf ("2. Home Sample Collection\n");	//0
  int choicetest;
  printf ("\nEnter Service Index: ");
  scanf ("%d", &choicetest);
  printf ("\n");
                                                            //In Centre Sample Collection
  if (choicetest == 1)
	{
	  struct add_test *ptr;
	  ptr = top2;
	  printf ("You have selected option 1\n");
	  while (ptr != NULL)
		{
		  printf ("%d. %s\n", ptr->test_index, ptr->test_name);
		  ptr = ptr->next;
		}
	  int choicetest1;
	  printf ("\nEnter Your test index number: ");
	  scanf ("%d", &choicetest1);
	  ptr = top2;
	  while (ptr != NULL)
		{
		  if (choicetest1 == ptr->test_index)
			{
			  printf ("\n%s\n", ptr->test_name);
			  printf ("Fee: %d\n", ptr->fees);
			  printf ("Time: %d\n", ptr->time);

			  ptr->tcount++;
			  printf ("Your serial number is : %d\n", ptr->tcount++);
			}
		  ptr = ptr->next;
		}

	}
                                                                    //Home Service Section

  if (choicetest == 2)
	{
	  struct add_test *ptr;
	  ptr = top2;
	  printf ("You have selected option 2\n");
	  while (ptr != NULL)
		{
		  if (ptr->homeservice == 1)
			{
			  printf ("%d. %s\n", ptr->test_index, ptr->test_name);
			}
		  ptr = ptr->next;
		}
	  int choicetest2;
	  printf ("\nEnter Your test index number: ");
	  scanf ("%d", &choicetest2);
	  ptr = top2;
	  while (ptr != NULL)
		{
		  if (choicetest2 == ptr->test_index)
			{
			  printf ("\n%s\n", ptr->test_name);
			  printf ("Fee: %d\n", ptr->fees);
			  printf ("Time: %d\n", ptr->time);
			  ptr->tcount++;
			  printf ("Your serial number is : %d\n", ptr->tcount);
			}
		  ptr = ptr->next;
		}
	}
  printf ("===================================================\n");
}

									                            //Blood Segement
struct blood
{
  char name[30];
  int age;
  char sex[10];
  char address[50];
  char phone[15];
  char mail[30];
  char lastdonationdate[10];
  char bloodgroup[3];
  char RH;
  struct blood *next;
};


										//Adding Blood Donors manually from main function
struct blood *topblood = NULL;
void
add_donors (const char *name, int age, const char *sex, const char *address,
			const char *phone, const char *mail, const char *lastdonationdate,
			const char *bloodgroup, char RH)
{
  struct blood *new_donor = (struct blood *) malloc (sizeof (struct blood));
  if (new_donor == NULL)
	{
	  printf ("Memory allocation failed!\n");
	  return;
	}
  strcpy (new_donor->name, name);
  new_donor->age = age;
  strcpy (new_donor->sex, sex);
  strcpy (new_donor->address, address);
  strcpy (new_donor->phone, phone);
  strcpy (new_donor->mail, mail);
  strcpy (new_donor->lastdonationdate, lastdonationdate);
  strcpy (new_donor->bloodgroup, bloodgroup);
  new_donor->RH = RH;
  new_donor->next = topblood;
  topblood = new_donor;

}

										//Adding Blood Donors To Stack by user

void
add_donor ()
{
  struct blood *new_donor = (struct blood *) malloc (sizeof (struct blood));
  if (new_donor == NULL)
	{
	  printf ("Memory allocation failed.\n");
	  return;
	}

  printf ("Enter Your Name: ");
  fgets (new_donor->name, sizeof (new_donor->name), stdin);

  printf ("Enter Your Age: ");
  scanf ("%d", &new_donor->age);
  getchar ();

  printf ("Enter Your Sex: ");
  fgets (new_donor->sex, sizeof (new_donor->sex), stdin);

  printf ("Enter Your Address: ");
  fgets (new_donor->address, sizeof (new_donor->address), stdin);

  printf ("Enter Your Phone Number: ");
  fgets (new_donor->phone, sizeof (new_donor->phone), stdin);

  printf ("Enter Your Mail Address: ");
  fgets (new_donor->mail, sizeof (new_donor->mail), stdin);

  printf ("Enter Your Last Blood Donation Date: ");
  fgets (new_donor->lastdonationdate, sizeof (new_donor->lastdonationdate),
		 stdin);

  printf ("Enter Your Blood Group: ");
  scanf (" %s", new_donor->bloodgroup);
  getchar ();

  printf ("Enter Your Rh: ");
  scanf (" %c", &new_donor->RH);

  new_donor->next = topblood;
  topblood = new_donor;

  printf
	("\t\t\t\t\tCongratulations!!\nYou have successfully Registered As a blood Donor.\n");
}

													// Functions for Finding Donor

void
find_donor ()
{
  printf ("You have selected Option 2\n");
  printf ("Patient Name: ");
  char name[30];
  scanf ("%s", name);
  getchar ();					

  printf ("Patient Age: ");
  int patient_age;
  scanf ("%d", &patient_age);
  getchar ();					

  printf ("Enter Blood Group: ");
  char blood_group[3];
  scanf (" %s", blood_group);
  getchar ();					

  printf ("Enter Your Rh: ");
  char rh_factor;
  scanf (" %c", &rh_factor);
  getchar ();

  struct blood *ptr = topblood;
  printf ("Donor list: \n\n");
  
  int flag = 0;
  while (ptr != NULL)
	{
	  if (strcmp (ptr->bloodgroup, blood_group) == 0 && ptr->RH == rh_factor)
		{
		  printf ("Name: %s\n", ptr->name);
		  printf ("Age: %d years\n", ptr->age);
		  printf ("Sex: %s\n", ptr->sex);
		  printf ("Address: %s\n", ptr->address);
		  printf ("Phone: %s\n", ptr->phone);
		  printf ("Email Address: %s\n", ptr->mail);
		  printf ("Last Donation Date: %s\n\n", ptr->lastdonationdate);
          flag++;
		}
	  ptr = ptr->next;
	}
    if(flag == 0)
    printf("No Match Found.\n");
}



														//Asking user in blood Donation segemnt
void
bloodDonation ()
{
  printf ("What Are You Looking For?\n");
  printf ("1. Want To Donate Blood?\n");
  printf ("2. Find Blood.\n");

  int choiceblood;
  scanf ("%d", &choiceblood);
  getchar ();

  if (choiceblood == 1)
	{
	  add_donor ();
	}
  if (choiceblood == 2)
	{
	  find_donor ();
	}
}

														//structure of health Packages

struct health_pack
{
  int index_health;
  char package_name[100];
  int original_rate;
  int package_rate;
  struct health_pack *next;
};

struct health_pack *top_health_pack = NULL;

void
addhealthPacks (int index_health, const char *package_name, int original_rate,
				int package_rate)
{
  struct health_pack *new_pack =
	(struct health_pack *) malloc (sizeof (struct health_pack));
  if (new_pack == NULL)
	{
	  printf ("Memory allocation failed!\n");
	  return;
	}
  new_pack->index_health = index_health;
  strcpy (new_pack->package_name, package_name);
  new_pack->original_rate = original_rate;
  new_pack->package_rate = package_rate;
  new_pack->next = top_health_pack;
  top_health_pack = new_pack;
}


void
add_health_manually ()
{
  struct health_pack *new_pack = malloc (sizeof (struct health_pack));
  if (new_pack == NULL)
	{
	  printf ("Memory allocation failed!\n");
	  return;
	}

  printf ("Enter health pack index: ");
  scanf ("%d", &new_pack->index_health);

  printf ("Enter package name: ");
  scanf ("%s", new_pack->package_name);

  printf ("Enter original rate: ");
  scanf ("%d", &new_pack->original_rate);

  printf ("Enter package rate: ");
  scanf ("%d", &new_pack->package_rate);

  new_pack->next = top_health_pack;
  top_health_pack = new_pack;
}

void
display_package ()
{
  struct health_pack *ptr = top_health_pack;
  if (ptr == NULL)
	{
	  printf ("No health packages available.\n");
	  return;
	}
  printf ("Health Packages:\n");
  printf
	("------------------------------------------------------------------------------------------------------------------------------\n");
  printf ("| %-10s | %-73s | %-15s | %-15s |\n", "Index", "Package Name",
		  "Original Rate", "Package Rate");
  printf
	("------------------------------------------------------------------------------------------------------------------------------\n");
  while (ptr != NULL)
	{
	  printf ("| %-10d | %-73s | %-15d | %-15d |\n", ptr->index_health,
			  ptr->package_name, ptr->original_rate, ptr->package_rate);
	  ptr = ptr->next;
	}
  printf
	("------------------------------------------------------------------------------------------------------------------------------\n");
}


																	//Admin Validation Checker
void
check_validation ()
{
  const char username[] = "hakuna";
  const char pass[] = "Matata";
  char input_username[20];
  char input_pass[20];
  int attempts = 0;
  const int max_attempts = 3;

  while (attempts < max_attempts)
	{
	  printf ("Enter your username: ");
	  scanf ("%s", input_username);
	  printf ("Enter your Password: ");
	  scanf ("%s", input_pass);

	  if (strcmp (username, input_username) == 0
		  && strcmp (pass, input_pass) == 0)
		{
		  printf ("Login successful!\n\n");
		  printf
			("Select Service: \n1. Add New Doctor.\n2. Add New Test.\n3. Add Health Packages.\n\nEnter Index Number.\n");
		  int adminchoice;
		  scanf ("%d", &adminchoice);
		  switch (adminchoice)
			{
			case 1:
			  add_doctor_manually ();
			  break;
			case 2:
			  add_test_manually ();
			  break;
			case 3:
			  add_health_manually ();
			  break;
			default:
			  printf ("Invalid choice\n");
			}
		  return;
		}
	  else
		{
		  printf ("Invalid username or password. Please try again.\n");
		  attempts++;
		}
	}

  printf ("Maximum number of attempts reached. Login failed.\n");
}

																		//Main Function
int
main ()
{
  printf ("\t\t\t\t\tHello\n");
  printf ("\t\t\tWelcome to SAST Medical\n");

  printf ("Enter your Name: ");
  char name[30];
  fgets (name, sizeof (name), stdin);

  printf ("Enter your Phone Number: ");
  char cell[30];
  scanf ("%s", cell);
                                                            // Doctor Adding Section

  add_doctor (50, 6, "Dr. Ratan Das Gupta", "017XX-XXXXXX", 1200,
			  "MBBS, FCPS (Medicine), MD (Nephrology)", "Neurologist",
			  "Shaheed Suhrawardy Medical Collage",
			  "5.30pm to 8pm (Closed: Friday)");

  add_doctor (49, 6, "Dr. Mofizur Rahman", "017XX-XXXXXX", 1000,
			  " MBBS, Diploma in Clinical Neurology (UK), MSc Neuroscience (UK)",
			  "Neurologist", "Chittagong Medical Collage ",
			  "6pm to 8pm (Closed: Friday)");

  add_doctor (48, 6, "Brig. Gen. Prof Dr. Ismail Chowdhury", "017XX-XXXXXX",
			  800, "MBBS, FCPS (Medicine), MD (Neurology)", "Neurologist",
			  "Dhaka Medical Coliage", "10am to 1pm (Closed: Friday)");

  add_doctor (47, 6, "Dr. Rama Biswas", "017XX-XXXXXX", 600,
			  " MBBS, FCPS (Medicine), MD (Neurology)", "Neurologist",
			  " Mymenshing Medical Collage", "9am to 11am (Closed: Friday)");

  add_doctor (46, 6, "Prof. Dr. A M Rejaus Satter", "017XX-XXXXXX", 1200,
			  "MBBS, FCPS (Surgery), MS (Neurosurgery)", "Neurologist",
			  "Sir Salimullah Medical Collage",
			  "5pm to 8pm (Closed: Friday)");

  add_doctor (45, 6, "Prof. Dr. Ari George Chacko", "017XX-XXXXXX", 1000,
			  " M. Ch (Neurosurgery)", "Neurologist",
			  "Christian Medical Collage Vellore",
			  "9am to 11am (Closed: Friday)");

  add_doctor (44, 6, "Dr. Md. Sirazul Haque Ershad", "017XX-XXXXXX", 800,
			  ": MBBS, MS (Neurosurgery), Fellowship in Neuro intervention (INK, India)",
			  "Neurologist", "Sher-e-Bangla Medical Collage",
			  "5pm to 8pm (Closed: Mon & Friday)");

  add_doctor (43, 2, "Dr. Raihan Rabbani", "017XX-XXXXXX", 600,
			  "MBBS, FCPS, US Board Certified in Internal Medicine",
			  "General Practitioner", "Dhaka Medical Collage",
			  "10am to 1pm (Closed: Friday)");

  add_doctor (42, 2, "Prof. Dr. Md. Abu Bakar", "017XX-XXXXXX", 800,
			  "MBBS, FCPS (Internal Medicine), FACP (USA), FRCP (Edin)",
			  "General Practitioner", "Sher-e-Bangla Medical Collage",
			  "5pm to 8pm (Closed: Friday)");

  add_doctor (41, 2, "Dr. Deepankar Kumar Basak", "017XX-XXXXXX", 1000,
			  " MBBS (DMC), FCPS (Internal Medicine)", "General Practitioner",
			  "Dhaka Medical Collage", "3pm to 6pm (Closed: Friday)");

  add_doctor (40, 2, "Prof. Dr. Arif Salam Khan", "017XX-XXXXXX", 1000,
			  " MBBS, FCPS (Surgery)", "General Practitioner",
			  "Dhaka Medical Collage", "11am to 3pm (Closed: Friday)");

  add_doctor (39, 2, "Prof. Dr. Md. Sanawar Hossain", "017XX-XXXXXX", 900,
			  "MBBS, MD, FCPS, FAMASI", "General Practitioner",
			  "Dhaka Medical Collage", "10am to 1pm (Closed: Friday)");

  add_doctor (38, 2, "Dr. Mohammad Abdullah Al Mamun", "017XX-XXXXXX", 800,
			  "MBBS, FCPS, MRCS", "General Practitioner", "MAS",
			  "5.30pm to 8pm (Closed: Friday)");

  add_doctor (37, 2, "Dr. Mohammad Israt Faisal", "017XX-XXXXXX", 600,
			  "MBBS, FCPS (Surgery)", "General Practitioner",
			  "Rangpur Medical Collage", "5pm to 7.30pm (Closed: Friday)");

  add_doctor (36, 2, "Dr. Mohammad Israt Faisal", "017XX-XXXXXX", 1000,
			  "MBBS, FCPS (Surgery)", "General Practitioner",
			  "Rangpur Medical Collage",
			  "11am to 1pm & 5pm to 8pm (Closed: Friday)");

  add_doctor (35, 2, "Dr. Tanny Tarafder", "017XX-XXXXXX", 800,
			  " MBBS, FCPS (Surgery), MRCS (UK)", "General Practitioner",
			  "Sir Salimullah Medical Collage ",
			  "10am to 1pm & 5pm to 8pm (Closed: Friday)");

  add_doctor (34, 2, "Dr. Mohammad Yasin Chowdhury", "017XX-XXXXXX", 700,
			  "MBBS, FCPS, MS, FMAS (India), FACS (USA)",
			  "General Practitioner", "Sylhet MAG Osmani Medical Collage",
			  "10am to 1pm & 5pm to 8pm (Closed: Friday)");

  add_doctor (33, 1, "Prof. Dr. Sohely Rahman", "017XX-XXXXXX", 800,
			  "MBBS, FCPS (Physical Medicine)",
			  "Emergency Medicine Physician", "Rajshahi Medical Collage",
			  "10.30am to 1pm & 5pm to 7.30pm (Closed: Friday)");

  add_doctor (32, 1, ". Prof. Dr. M. A. Rashid", "017XX-XXXXXX", 1000,
			  " MBBS, FCPS (Specialist Pain, Paralysis & Rheumatic Diseases)",
			  "Emergency Medicine Physician", "Mymenshing Medical Collage",
			  "11am to 1pm & 5pm to 8pm (Closed: Friday)");

  add_doctor (31, 8, "Prof. Dr. Md. Hasan Masud", "017XX-XXXXXX", 1000,
			  " MBBS, MD (Gastroenterology)", "Gastroenterologist",
			  "Sher-e-Bangla Medical Collage",
			  "10am to 1pm & 4pm to 8pm (Closed: Friday)");

  add_doctor (30, 8, "Dr. Fowaz Hussain Shuvo", "017XX-XXXXXX", 600,
			  " MBBS, MD (Hepatology)", "Gastroenterologist",
			  "Dhaka Medical Collage",
			  "10am to 1pm & 4pm to 8pm (Closed: Friday)");

  add_doctor (29, 8, "Prof. Dr. Sk. Md. Bahar Hussain", "017XX-XXXXXX", 900,
			  "MBBS, FCPS (Medicine), FACP (USA), FRCP (Edin), F. Gastro (Shanghai), FRCP (Glasgow)",
			  "Gastroenterologist", "Sher-e-Bangla Medical Collage",
			  "4pm to 8pm (Closed: Friday)");

  add_doctor (28, 8, "Brig. Gen. Dr. Md. Delwar Hossain", "017XX-XXXXXX", 800,
			  " MBBS, FCPS (Medicine),FCPS (Gastroenterology)",
			  "Gastroenterologist", "Dhaka Medical Collage",
			  "6pm to 8pm (Closed: Friday)");

  add_doctor (27, 7, "Dr. Pratik Dewan", "017XX-XXXXXX", 800,
			  " MBBS, DEM, MD (Internal Medicine), BIRDEM Academy",
			  "Endocrinologist", "Sher-e-Bangla Medical Collage",
			  "10am to 1pm & 5pm to 8pm (Closed: Friday)");

  add_doctor (26, 9, "Prof. Dr. Fariah Sharmeen", "017XX-XXXXXX", 1200,
			  "MBBS, FCPS (Radiotherapy)", "Oncologist",
			  "Cumilla Medical Collage", "5pm to 7.30pm (Closed: Friday)");

  add_doctor (25, 9, "Prof. Dr. Syed Md. Akram Hussain", "017XX-XXXXXX", 1000,
			  "MBBS, FCPS, FRCP (Glasgow), FRCP (Edinburgh), FACP (USA), MRCR (UK)",
			  "Oncologist", "Square Hospital Limited,Dhaka",
			  " 9am to 9pm (Closed: Friday)");

  add_doctor (24, 9, "Dr. Arunangshu Das", "017XX-XXXXXX", 1200,
			  "MBBS, BCS (Health), FCPS (Radiotherapy)", "Oncologist",
			  "Mymenshing Medical Collage", "5pm to 7.30pm (Closed: Friday)");

  add_doctor (23, 9, " Dr. Md. Salim Reza", "017XX-XXXXXX", 1000,
			  "MBBS, DMRT, FCPS", "Oncologist",
			  "Sylhet MAG Osmani Medical Collage",
			  "5pm to 7pm (Closed: Friday)");

  add_doctor (22, 4, " Dr. Nasima Shaheen", "017XX-XXXXXX", 900,
			  "MBBS, DGO, MCPS, FCPS", "Obstetrician & Gyneocologist",
			  "Dhaka Medical Collage",
			  "10am to 2pm & 4pm to 8pm (Closed: Friday)");

  add_doctor (21, 4, " Dr. Rina Haider", "017XX-XXXXXX", 800,
			  "MBBS, FCPS (Gyn&Obs)", "Obstetrician & Gyneocologist",
			  "Mymenshing Medical Collage", " 5pm to 7pm (Closed: Friday)");

  add_doctor (20, 4, "Dr. Kashefa Nazneen", "017XX-XXXXXX", 700,
			  " MBBS, FCPS", "Obstetrician & Gyneocologist",
			  "Rajshahi Medical Collage",
			  "10am to 1pm & 4pm to 8pm (Closed: Friday)");

  add_doctor (19, 4, " Prof. Dr. Rehana Parveen", "017XX-XXXXXX", 1000,
			  " MBBS, FCPS", "Obstetrician & Gyneocologist",
			  "Sher-e-Bangla Medical Collage",
			  "10am to 1pm & 5pm to 8pm (Closed: Friday)");

  add_doctor (18, 4, " Dr. Farzana Rashid", "017XX-XXXXXX", 800,
			  "FCPS ( OBS-GYN)", "Obstetrician & Gyneocologist",
			  "Mymenshing Medical Collage", "5pm to 9pm (Closed:Friday)");

  add_doctor (17, 4, "Dr. Nargis Fatema", "017XX-XXXXXX", 900,
			  " MBBS, FCPS (OBS-GYN)", "Obstetrician & Gyneocologist",
			  "Sir Salimullah Medical Collage",
			  "5pm to 7pm (Closed: Mon & Friday)");

  add_doctor (16, 4, "Dr. Nazneen Ara Begum", "017XX-XXXXXX", 1200,
			  " MBBS, FCPS (OBS-GYN)", "Obstetrician & Gyneocologist",
			  "University of Science and Technology Chittagong",
			  "5pm to 7pm (Closed: Mon & Friday)");

  add_doctor (15, 4, "Dr.Razia Parvin", "017XX-XXXXXX", 800,
			  "MBBS,FCPS(Gyne & Obs)", "Obstetrician & Gyneocologist",
			  "Sylhet MAG Osmani Medical Collage",
			  "4.30pm to 6pm (Closed: Mon & Friday)");

  add_doctor (14, 4, "Dr.Taimoon Nahar Khanom", "10616", 1000,
			  "MBBS,FCPS(Gyne & Obs)", "Obstetrician & Gyneocologist",
			  "Rajshahi Medical Collage", "5pm to 7.30pm (Closed: Friday)");

  add_doctor (13, 4, "Dr.Kaniz Akther", "017XX-XXXXXX", 800,
			  "MBBS,FCPS(OBS-GYN)", "Obstetrician & Gyneocologist",
			  "Jahurul Islam Medical Collage",
			  "10am to 1pm & 4pm to 8pm (Closed: Friday)");

  add_doctor (12, 4, "Dr.Khaleda Yeasmin Mirza", "017XX-XXXXXX", 1000,
			  "Mbbs,DGO(Ireland),Arab Board,KSA",
			  "Obstetrician & Gyneocologist", "Chittagong Medical Collage",
			  "10am to 1pm & 4pm to 8pm (Closed: Friday)");

  add_doctor (11, 4, "Dr.Kazi Shamsun Nahar", "017XX-XXXXXX", 900,
			  "MBBS,FCPS(Gyn)", "Obstetrician & Gyneocologist",
			  "Khulna Medical Collage",
			  "10am to 1pm & 4pm to 7pm (Closed: Friday)");

  add_doctor (10, 7, "Dr. Sadiqa Tuqan", "017XX-XXXXXX", 700,
			  "MBBS,FCPS(Endocrinology and Metabolism)", "Endocrinologist",
			  "Mymenshing Medical Collage",
			  "10am to 1pm & 4pm to 7pm (Closed: Friday)");

  add_doctor (9, 10, "Prof Dr. Md. Siraj Uddin", "017XX-XXXXXX", 600,
			  "MBBS.DDV(BSMMU),DD(Bangkok)Fellow-Dermatosurgery & Laser(Bangkok),Fellow-Hair Transplant Surgery,New York University,USA",
			  "Dermatologist", "Sylhet MAG Osmani Medical Collage",
			  "11am to 1pm & 4pm to 8pm (Closed: Thu & Friday)");

  add_doctor (8, 10, "Dr.Syeda Ishrat Jahan", "017XX-XXXXXX", 800,
			  "MBBS,DDV(SINGAPORE),MSc in Clinical Dermatology(Lomdon),MSSVD(London)",
			  "dermatologist", "Sylhet MAG Osmani Medical Collage",
			  "10am to 1pm (Closed: Friday)");

  add_doctor (7, 3, "Dr.Mejor (Retd.)Zeena Salwa", "017XX-XXXXXX", 1200,
			  "MBBS,DCH,FCPS(pead),Clinical Training on pediatric Neurology,Training on EEG and Epilepsy in USA",
			  "Pediatrician", "Rangpur Medical Collage",
			  "9am to 5pm (Closed: Friday)");

  add_doctor (6, 5, "Dr.Mahbub Mansur", "017XX-XXXXXX", 800,
			  "MBBS ,MD,International cardiology fellow", "Cardiologist",
			  "Chittagong Medical Collage", "9am to 5pm (Closed: Friday)");

  add_doctor (5, 5, "Dr.kamal Pasha", "017XX-XXXXXX", 1200, "MBBS,FCPS,FICS",
			  "Cardiologist", "Sir Salimullah Medical Collage",
			  "9am to 5pm (Closed: Friday)");

  add_doctor (4, 5, "Dr.Md Chadekul Islam Shikder Shyamal", "01740486123",
			  700, "MBBS,MD card,FCPS", "Cardiologist",
			  "Dhaka Medical Collage", "6pm to 9pm (Closed: Friday)");

  add_doctor (3, 5, "Dr.Mahbub Morshed", "01740486123", 600, "MBBS,D.Card",
			  "Cardiologist", "Dhaka Medical Collage",
			  "5pm to 9pm (Closed: Friday)");

  add_doctor (2, 5, "Dr. Muhammad Moniruzzaman", "01740486123", 600,
			  "MBBS ,Ms(CV & TS)", "Cardiologist",
			  "Sir Salimullah Medical Collage", "7Pm-9pm (closed: Friday)");

  add_doctor (1, 5, "Dr. Abdullah Ahmed Solaiman", "01301254924", 800,
			  "MBBS,MD", "Cardiologist", "Dhaka Medical Collage",
			  "Mon & Thrusday 5:30pm - 7pm");



                                                                //Test Adding Section

  add_tests ("MRCP", 0, 26, 900, 14);
  add_tests ("HBs", 0, 25, 700, 14);
  add_tests ("Electroencephalogram (EEG)", 0, 24, 1250, 14);
  add_tests ("Allergy Testing (Skin prick test, Blood Test)", 0, 23, 850, 14);
  add_tests ("Renal Function Tests (RFTs)", 0, 22, 1000, 14);
  add_tests ("Liver Function Tests (LFTs)", 0, 21, 850, 14);
  add_tests ("Magnetic Resonance Imaging (MRI)", 0, 20, 1400, 14);
  add_tests ("Computed Tomography(CT) Scan", 0, 19, 600, 14);
  add_tests ("X-rays", 0, 18, 400, 14);
  add_tests ("Electrocardiogram(ECG or EKG)", 0, 17, 1200, 14);
  add_tests ("Ultrasonogram", 0, 16, 400, 14);
  add_tests ("Blood Glucose Test", 0, 15, 300, 14);
  add_tests ("Thyroid Function Tests", 0, 14, 750, 14);
  add_tests ("Lipid Profile", 0, 13, 550, 14);
  add_tests ("Urinalysis", 0, 12, 1000, 14);
  add_tests ("Blood Chemistry Panel", 0, 11, 1000, 14);
  add_tests ("Complete Blood Count(CBC)", 0, 10, 600, 14);
  add_tests ("Sleep Apnea Testing", 1, 9, 700, 14);
  add_tests ("Allergy Testing", 1, 8, 500, 14);
  add_tests ("Blood Collection for Hormone Testing", 1, 7, 950, 14);
  add_tests ("HIV Test", 1, 6, 400, 14);
  add_tests ("Saliva Hormone Testing", 1, 5, 500, 14);
  add_tests ("DNA Testing", 1, 4, 1300, 14);
  add_tests ("Sperm Analysis", 1, 3, 1000, 14);
  add_tests ("Pregnancy Test", 1, 2, 300, 14);
  add_tests ("Covid-19 Test", 1, 1, 400, 14);


                                                     //Blood Group Adding Segment

  add_donors ("Masud Rana", 20, "Male", "Dhaka", "01950430320", "NULL",
			  "2023-08-23", "AB", '-');
  add_donors ("Sagor", 22, "Male", "Dhaka", "01951410712", "NULL",
			  "2024-01-26", "O", '+');
  add_donors ("Anik Chandra Das", 21, "Male", "Dhaka", "01311071365", "NULL",
			  "2023-06-12", "B", '+');
  add_donors ("Md. Waliullah", 23, "Male", "Dhaka", "01837460013", "NULL",
			  "2024-02-03", "B", '+');
  add_donors ("Eng. kaium Chawdhury", 25, "Male", "Dhaka", "01911408687",
			  "NULL", "2023-09-23", "A", '+');
  add_donors ("Masudur Rahman", 30, "Male", "Dhaka", "01911524924", "NULL",
			  "2024-08-02", "O", '+');
  add_donors ("Rubel", 29, "Male", "Dhaka", "01706198000", "NULL",
			  "2024-01-04", "A", '-');
  add_donors ("Naim Khan", 19, "Male", "Dhaka", "01914632952", "NULL",
			  "2023-05-23", "A", '+');
  add_donors ("Ovi", 18, "Male", "Dhaka", "01906203717", "NULL", "2024-02-14",
			  "B", '+');
  add_donors ("Mahmud", 22, "Male", "Dhaka", "01629948420", "NULL",
			  "2024-05-28", "AB", '+');
  add_donors ("Rubel", 25, "Male", "Dhaka", "01781248824", "NULL",
			  "2023-08-18", "AB", '+');
  add_donors ("Al-Amin", 26, "Male", "Dhaka", "01646741649", "NULL",
			  "2023-09-15", "B", '+');
  add_donors ("Sohag Hossain", 21, "Male", "Dhaka", "018120202912", "NULL",
			  "2023-07-13", "A", '+');
  add_donors ("Rasel Khan Rana", 32, "Male", "Dhaka", "01719265244", "NULL",
			  "2024-01-04", "O", '+');
  add_donors ("Md. Sojib", 24, "Male", "Dhaka", "01777431849", "NULL",
			  "2024-03-12", "B", '+');
  add_donors ("Shorif Rabbu", 20, "Male", "Dhaka", "01819062297", "NULL",
			  "2024-01-02", "A", '+');
  add_donors ("AL-Amin", 26, "Male", "Dhaka", "01326190828", "NULL",
			  "2024-01-04", "B", '+');
  add_donors ("Sajjad hossen", 19, "Male", "Dhaka", "01609271048", "NULL",
			  "2023-09-03", "B", '+');
  add_donors ("Ershad", 21, "Male", "Dhaka", "01758981904", "NULL",
			  "2023-11-01", "O", '+');
  add_donors ("Sujon Mahmud", 20, "Male", "Dhaka", "01924936868", "NULL",
			  "2024-01-26", "A", '+');
  add_donors ("HOssain", 18, "Male", "Dhaka", "01306473008", "NULL",
			  "2024-01-11", "B", '+');
  add_donors ("Subash", 23, "Male", "Dhaka", "01985422884", "NULL",
			  "2023-09-16", "A", '+');
  add_donors ("Milon", 33, "Male", "Dhaka", "01940714131", "NULL",
			  "2023-11-23", "A", '-');
  add_donors ("Humayun", 16, "Male", "Dhaka", "021749615137", "NULL",
			  "2023-12-27", "O", '+');
  add_donors ("Faisal", 19, "Male", "Dhaka", "01628336719", "NULL",
			  "2023-08-19", "A", '+');
  add_donors ("Meraz", 22, "Male", "Dhaka", "01949156003", "NULL",
			  "2024-04-12", "A", '+');
  add_donors ("Faysal", 23, "Male", "Dhaka", "01313739014", "NULL",
			  "2024-02-22", "A", '+');
  add_donors ("Omar Hasan Shuvo", 18, "Male", "Dhaka", "01568254769", "NULL",
			  "2023-12-25", "O", '+');
  add_donors ("Nijamul Islam", 26, "Male", "Dhaka", "01717554587", "NULL",
			  "2024-1-05", "O", '+');
  add_donors ("Arman", 23, "Male", "Dhaka", "01647251811", "NULL",
			  "2024-02-15", "O", '+');
  add_donors ("Nayeem", 19, "Male", "Dhaka", "01739644391", "NULL",
			  "2024-01-06", "B", '+');
  add_donors ("Aman", 30, "Male", "Dhaka", "01670195015", "NULL",
			  "2024-01-19", "O", '+');
  add_donors ("Ishan", 27, "Male", "Dhaka", "01877682810", "NULL",
			  "2024-02-16", "A", '+');
  add_donors ("Sarowar", 31, "Male", "Dhaka", "01676823662", "NULL",
			  "2024-01-10", "B", '+');
  add_donors ("Nayem", 25, "Male", "Dhaka", "01914632952", "NULL",
			  "2024-03-29", "A", '+');
  add_donors ("Jasim", 29, "Male", "Dhaka", "01641167224", "NULL",
			  "2024-02-16", "A", '+');
  add_donors ("Asad", 27, "Male", "Dhaka", "01721295784", "NULL",
			  "2024-04-20", "AB", '+');
  add_donors ("Sakib", 30, "Male", "Dhaka", "01747746722", "NULL",
			  "2024-04-09", "A", '+');
  add_donors ("Amran", 35, "Male", "Dhaka", "01647251811", "NULL",
			  "2024-02-26", "O", '+');
  add_donors ("Symon", 22, "Male", "Dhaka", "01703452387", "NULL",
			  "2024-04-16", "A", '+');
  add_donors ("Bayezid", 28, "Male", "Dhaka", "01636339472", "NULL",
			  "2024-02-20", "A", '+');
  add_donors ("Rakib", 29, "Male", "Dhaka", "01407632454", "NULL",
			  "2024-04-11", "O", '+');
  add_donors ("Raihan", 37, "Male", "Dhaka", "01835922291", "NULL",
			  "2024-01-30", "B", '+');
  add_donors ("Rashed", 35, "Male", "Dhaka", "01711167623", "NULL",
			  "2024-03-07", "B", '+');
  add_donors ("Sabbir", 23, "Male", "Dhaka", "01735361735", "NULL",
			  "2024-01-06", "O", '+');
  add_donors ("Parvez", 26, "Male", "Dhaka", "01921013561", "NULL",
			  "2024-04-06", "O", '+');
  add_donors ("Tanjina", 27, "Female", "Dhaka", "01732401501", "NULL",
			  "2024-03-28", "O", '-');
  add_donors ("Masrafi", 25, "Male", "Dhaka", "01712227985", "NULL",
			  "2024-01-10", "A", '+');
  add_donors ("Shamin", 23, "Male", "Dhaka", "01724955569", "NULL",
			  "2024-04-16", "A", '+');
  add_donors ("TUshar", 21, "Male", "Dhaka", "01742768831", "NULL",
			  "2024-02-11", "O", '+');

                                                //packages 

  addhealthPacks (21, "Smoker Health Check-up Package", 4661, 3100);
  addhealthPacks (20, "Child Health Check-up (4 years to 16 years)", 7565,
				  4900);
  addhealthPacks (19, "Pre-Marital Check-up Package", 6483, 4100);
  addhealthPacks (18, "Pre-Employment Health Check-up Package", 3433, 2250);
  addhealthPacks (17, "Cancer Screening Package for Female", 9933, 5900);
  addhealthPacks (16, "Cancer Screening Package for Male", 7115, 4350);
  addhealthPacks (15, "Renal/Kidney Screening Package", 6279, 4000);
  addhealthPacks (14, "Thyroid Check-up Package", 6561, 4150);
  addhealthPacks (13, "Standard Diabetic Check-up Package", 6758, 4300);
  addhealthPacks (12, "Primary Diabetic Check-up Package", 3090, 1950);
  addhealthPacks (11, "Liver Check-up Package-2 (Suffering)", 10797, 7200);
  addhealthPacks (10, "Liver Check-up Package-1 (Suspected)", 5204, 3500);
  addhealthPacks (9, "Cardiac Check-up Package-2 (Suffering)", 8372, 5800);
  addhealthPacks (8, "Cardiac Check-up Package-1 (Suspected)", 7372, 5050);
  addhealthPacks (7,
				  "Comprehensive Health Check-up for Female (Post-menopausal/Above 40 years)",
				  24794, 16000);
  addhealthPacks (6,
				  "Comprehensive Health Check-up for Male (Above 40 years)",
				  20194, 12750);
  addhealthPacks (5,
				  "Executive Health Check-up for Female (Post-menopausal/Above 40 years)",
				  16944, 10900);
  addhealthPacks (4, "Executive Health Check-up for Male (Above 40 years)",
				  12144, 7550);
  addhealthPacks (3, "Executive Health Check-up for Female (Up 40 years)",
				  11076, 7200);
  addhealthPacks (2, "Executive Health Check-up for Male (Up 40 years)", 8276,
				  5250);
  addhealthPacks (1, "Basic Health Check-up for Male/Female (Adult)", 8015,
				  5200);


  while (1)
	{
	  printf ("\nSelect your services: \n");
	  printf ("1. Doctor Appointment.\n");
	  printf ("2. Test & Reports.\n");
	  printf ("3. Find Blood Donors.\n");
	  printf ("4. HealthCare Packages.\n");
	  printf ("5. Admin\n");

	  int response;
	  printf ("\nEnter Service Index: ");
	  scanf ("%d", &response);

	  switch (response)
		{
		case 1:
		  display_doctors ();
		  break;
		case 2:
		  test_reports ();
		  break;
		case 3:
		  bloodDonation ();
		  break;
		case 4:
		  display_package ();
		  break;
		case 5:
		  check_validation ();
		  break;
		default:
		  printf ("Invalid choice\n");
		}
	}
  return 0;
}