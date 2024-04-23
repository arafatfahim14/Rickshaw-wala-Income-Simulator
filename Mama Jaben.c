#include <stdio.h>
#include <math.h>
#include <string.h>

#define sadharon_vara 20
#define rickshaw_vara 600 //Define 600 as rickshaw vara (varay calito rickshaw)

typedef struct { //Using typedef to define a structure type as Jayga
    char nam[50]; //nam of the jayga
    float durotto; //durotto of the jayga
} Jayga;

int main (void)

{
    Jayga sadharon_jayga[] = { //Jayga type string named sadharon jayga
      {"TSC Mor", 8.5},
      {"Motalib Plaza", 6},
      {"Multiplan", 6.1},
      {"Rabindra Sarbar", 4},
      {"Mohammadpur Bus Stand", 1.6},
      {"Shia Mosjid", 1.4},
      {"Nur Jahan Road", 1.7},
      {"Krishi Market", 2},
      {"Camp Bazar", 2.6},
      {"Ibn Sina", 2.7},
      {"Bashundhara City Complex", 5.4},
      {"Green City Riverside Walkway", 1.9},
      {"Dhaka Uddan", 0.75}
    };
    int motmat_sadharon_jayga = sizeof(sadharon_jayga)/sizeof(sadharon_jayga[0]);

    float income = 0;
    int rickshaw_vara_covered = 0; //A flag to check if rickshaw vara (600TK) covered or not
    int otirikto_vara = 0; //A flag to set otirikto vara
    int i,j; //For loop

    for (i = 0; i < 10; i++)
        {
            int iccha;
            char jeikhane_jabo_tar_nam[50];

            //Propose for a trip
            printf("\nProposal %d:\n", i + 1); //Counting Proposal Numbers
            printf("\nRickshaw wala mama: Mama Jaben?\n");
            printf("Amar response (ho/na): ");
            scanf("%s", jeikhane_jabo_tar_nam); // Read ho/na as a string

            if (strcmp(jeikhane_jabo_tar_nam, "ho") == 0)
                {

                    Jayga jeikhane_jabo;

                    // Show sadharon jayga
                    printf("\n\n");
                    for (j = 0; j < motmat_sadharon_jayga; j++)
                    {
                        printf("%d. %s (%.2f km)\n", j + 1, sadharon_jayga[j].nam, sadharon_jayga[j].durotto);
                    }

                    printf("\nEi jayga gulor vitore kothao jaben (ho/na) naki onno kothao (o)? ");
                    scanf("%s", jeikhane_jabo_tar_nam); // Read ho, na, or onno kothao (o)

                    if (strcmp(jeikhane_jabo_tar_nam, "ho") == 0)
                        {

                            printf("\nKi vablen koi jaben? (Bad dite caile 0 capen): ");
                            scanf("%d", &iccha);

                            if (iccha > 0 && iccha <= motmat_sadharon_jayga)
                                {
                                    jeikhane_jabo = sadharon_jayga[iccha - 1];
                                }
                            else
                                {
                                    printf("\nKi mama vul-val koren khali.\n"); //If given a invalid input
                                    continue;
                                }
                        }
                    else if (strcmp(jeikhane_jabo_tar_nam, "o") == 0)
                        {
                            printf("\nKoi jaben? : ");
                            scanf("%s", jeikhane_jabo_tar_nam);

                            printf("\nJaygata kotodur (in km)?: ");
                            scanf("%f", &jeikhane_jabo.durotto);

                            strcpy(jeikhane_jabo.nam, jeikhane_jabo_tar_nam);
                        }
                    else
                        {
                            printf("Ki mama vul-val koren khali.\n");
                            continue;
                        }


                    int round_figure_hisab = (int)round(jeikhane_jabo.durotto); //float type durotto to int type using round function
                    float vara;

                    if (otirikto_vara)
                        {
                            vara = round_figure_hisab * (sadharon_vara * 1.3); //1.3 gun otirikto vara per KM
                        }
                    else
                        {
                            vara = round_figure_hisab * sadharon_vara;
                        }

                    if (vara < sadharon_vara) //Minimum vara 20 TK
                        {
                            vara = sadharon_vara;
                        }

                    printf("\n%s jaite %.2f taka lagbe\n", jeikhane_jabo.nam, vara);

                    printf("Ei takay hoile colen naile thak. (1 for colo jai, 0 for na thak): ");
                    scanf("%d", &iccha);

                    if (iccha)
                        {
                            income += vara;
                            printf("\nUthen\t Bismillah.");

                            if (income >= rickshaw_vara && !rickshaw_vara_covered)
                                {
                                    printf("\nAlhamdulillah. Mama varar taka uthaiya felse.\n");
                                    rickshaw_vara_covered = 1;
                                    otirikto_vara = 0; // Reset the flag of otirikto vara
                                }
                            else if (!rickshaw_vara_covered)
                                {
                                    if (i >= 3) //Increase the vara after 3rd trip if rent not covered
                                        {
                                            otirikto_vara = 1;
                                        }
                                    else
                                        {
                                            otirikto_vara = 0;
                                        }
                                }
                        }
                    else
                        {
                            printf("\nAccha valo thaken.\n");
                        }

                }
            else
                {
                    printf("\nAccha valo thaken.\n");
                }
        }

    printf("\nAjke motmat mamar total income hoilo: %.2f taka\n", income);

    return 0;
}
