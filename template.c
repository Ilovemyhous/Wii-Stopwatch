//By Ilovemyhouse

//TO-DO

//Finish translations
//Update the version
//Check if it works


//#include <gccore.h>
#include "wpad.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

#define A_GRAVE 0x00E0 
#define E_GRAVE 0x00E8 
#define E_AIGU 0x00E9 

//{
	//setlocale(LC_CTYPE, "");
	//printf("%lc", E_AIGU);
//}

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

//The logo is defined by the void variable
void afficheLogo(void){
		sleep(1);
		printf("                             \r");
		printf("				  _____ _                           _       _     \n");
		printf("				 /  ___| |                         | |     | |    \n");
		printf("				 \\ `--.| |_ ___  _ ____      ____ _| |_ ___| |__  \n");
		printf("				  `--. \\ __/ _ \\| '_ \\ \\ /\\ / / _` | __/ __| '_ \\ \n");
		printf("				 /\\__/ / || (_) | |_) \\ V  V / (_| | || (__| | | |\n");
		printf("				 \\____/ \\__\\___/| .__/ \\_/\\_/ \\__,_|\\__\\___|_| |_|\n");
		printf("				                | |                               \n");
		printf("				                |_|                               \n");
		printf(" \n");
		sleep(3);
}
//---------------------------------------------------------------------------------
int main(int argc, char **argv) {
//---------------------------------------------------------------------------------

	// Initialise the video system
	VIDEO_Init();

	// This function initialises the attached controllers
	WPAD_Init();

	// Obtain the preferred video mode from the system
	// This will correspond to the settings in the Wii menu
	rmode = VIDEO_GetPreferredMode(NULL);

	// Allocate memory for the display in the uncached region
	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

	// Initialise the console, required for printf
	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);

	// Set up the video registers with the chosen mode
	VIDEO_Configure(rmode);

	// Tell the video hardware where our display memory is
	VIDEO_SetNextFramebuffer(xfb);

	// Make the display visible
	VIDEO_SetBlack(FALSE);

	// Flush the video register changes to the hardware
	VIDEO_Flush();

	// Wait for Video setup to complete
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();

	// Detects the system language. Not used.
	//LANGUAGE_Init();
	//language = LANGUAGE_GetPreferredMode(NULL);


	// The console understands VT terminal escape codes
	// This positions the cursor on row 2, column 0
	// we can use variables for this with format codes too
	// e.g. printf ("\x1b[%d;%dH", row, column );
	printf("\x1b[2;0H");

	//Resets the timer
	int Hour = 00;
	int Minute = 00;
	int Second = 00;
	int Milli = 00;
	int Start = 0;
	bool Pause = false;

	//Get the system language
	int language = CONF_GetLanguage();
	printf("%d\n", language);
	//printf("%d\n", Start);
	
	switch(language){
		case 1: //Egnlish
			printf("Initialising. . . Please Wait\r");
			afficheLogo();
			printf("Homebrew made by Ilovemyhouse.\n");
			printf("Version 2.0.0 Alpha Dev\n");
			getchar();
			printf(" \n");
			printf("Press A to start the stopwatch.\n");
			printf("Press A again to make a lap.\n");
			printf("Press B to pause and resume the stopwatch.\n");
			printf("Press + to stop and reset the timer.\n");
			printf("Press - to see the credits.\n");
			printf("Press the HOME button to exit the stopwatch.\n");
			printf(" \n");
			break;
		case 2: //German
			printf("Initialisierung. . . Bitte warten\r");
			afficheLogo();
			printf("Homebrew von Ilovemyhouse.\n");
			printf("Version 2.0.0 Alpha Dev\n");
			getchar();
			printf(" \n");
			printf("Druecke A um die Stopuhr zu starten.\n");
			printf("Druecke wieder A um eine Runde zu machen.\n");
			printf("Druecke auf B um die Stopuhr zu pausen und zu entpausen.\n");
			printf("Druecke + um die Stopuhr aufzuhalten, und zu reinitialisieren.\n");
			printf("Druecke - um die Kredite zu sehen.\n");
			printf("Druecke den HOME Knopf um die Stopuhr zu verlassen.\n");
			break;
		case 3: //French
			printf("Initialisation. . . Veuillez patienter\r");
			afficheLogo();
			printf("Homebrew fait par Ilovemyhouse.\n");
			printf("Version 2.0.0 Alpha Dev\n");
			getchar();
			printf(" \n");
			printf("Appuyez sur A pour demarrer le chronometre.\n");
			printf("Appuyez de nouveau sur A pour faire un tour.\n");
			printf("Appuyez sur + pour arrêter, et réinistialiser le chronometre.\n");
			printf("Appuyez sur B pour mettre le chronomètre sur pause et pour continuer.\n");
			printf("Appuyez sur - pour afficher les crédits\n");
			printf("Appuyez sur le bouton HOME pour quitter le chronometre.\n");
			break;
		case 5: //Italian by ReddyX_73#5472
			printf("Caricamento... Attendere\r");
			afficheLogo();
			printf("Homebrew realizzato da Ilovemyhouse.\n");
			printf("Versione 2.0.0 Alpha Dev\n");
			getchar();
			printf(" \n");
			printf("Premi A per avviare il cronometro.\n");
			printf("Premi A per fare un giro.\n");
			printf("Premi + per fermare e resettare il timer.\n");
			printf("Premi - per visualizzare i crediti.\n");
			printf("Premi B per stoppare e riprendere il cronometro.\n");
			printf("Premi il pulsante HOME per uscire dal cronometro.\n");
			break;
		case 7: //Dutch
			printf("Initialisatie. . . Wacht alsjeblieft\r");
			afficheLogo();
			printf("Homebrew gemaakt door Ilovemyhouse.\n");
	    	printf("Versie 2.0.0 Alpha Dev\n");
			getchar();
			printf(" \n");
			printf("Druk op A om de stopwatch te starten.\n");
			printf("Press A again to make a lap.\n");
			printf("Druk op - om de credits te zien\n");
			printf("Druk op + om de timer te stoppen en resetten.\n");
			printf("Druk op de HOME knop om uit de stopwatch te gaan.\n");
			break;
		default : //Translation missing
			printf("Error: Translation missing!\n");
			break;
	}

	while(1) {

		// Call WPAD_ScanPads each loop, this reads the latest controller states
		WPAD_ScanPads();

		// WPAD_ButtonsDown tells us which buttons were pressed in this loop
		// this is a "one shot" state which will not fire again until the button has been released
		u32 pressed = WPAD_ButtonsDown(0);

		//To exit the homebrew, you simply have to press the home button
		if ( pressed & WPAD_BUTTON_HOME ) break;
		{
			switch(language){
				case 1: //Anglais
					printf("Exiting...\r");
					break;

				case 2: //Allemand
					printf("Gehe raus...\r");
					break;

				case 3: //Français
					printf("Sortie...\r");
					break;

				case 5: //Italien
					printf("Uscita...\r");
					break;

				case 7: //Néerlandais
					printf("Afsluiten...\r");
					break;

				default : //Traduction manquante
					printf("Error: Translation missing, or error in the Code!\n");
					sleep(1);
					printf("Exiting...");
					break;
			}
			exit(0);
		}

		//Shows the timer beofre start, and then set's the start value to 1
		if ( pressed & WPAD_BUTTON_A ){
			//printf("%d\n", Start);
			if ( Start == 0 ){
				printf(" \n");
				printf("3\n");
				sleep(1);
				printf("	2\n");
				sleep(1);
				printf("		1\n");
				printf(" \n");
				sleep(1);
				//printf("%d\n", Start);
				Start = Start + 1;}
				//printf("%d\n", Start);
		}

		//Code to make laps
		if ( pressed & WPAD_BUTTON_A ){
			Start = Start + 1;
			if (Start < 1){
				printf("%d\n", Start);
				printf("								   %d:%d:%d:%d\r", Hour, Minute, Second, Milli);
					switch(language){
						case 1: //English
							printf("Lap!\n");
							break;
						case 2: //German
							printf("Runde!\n");
							break;
						case 3:	//French
							printf("Tour!\n");
							break;
						case 5: //Italian
							printf("Giro!\n");
							break;
						case 7: //Dutch
							printf("Toren!\n");
							break;
					}
			}
		}

		//Timer
		if ( Start > 1){
			if (Pause == true)
			{
				printf("Debug\n");
				break;
			}
			if (Pause == false)
				{
					//printf("Debug 2\n");
					Milli = Milli + 01;
					printf("								   %d:%d:%d:%d\r", Hour, Minute, Second, Milli);}
					if ( Milli > 59 ){
						Second = Second + 1;
						Milli = 00;
						if ( Second > 59){
							Minute = Minute + 1;
							Second = 0;
						}
							if ( Minute > 59 ){
								Hour = Hour + 1;
							Minute = 0;
							}
					}
				}	

		//Code to stop, and reset the stopwatch
		if ( pressed & WPAD_BUTTON_PLUS ){
			switch(language){
				case 1:	//Anglais
					printf("Stopped and reset!\n");
					Hour = 00;
					Minute = 00;
					Second = 00;
					Milli = 00;
					Start = 0;
					Pause = false;
					break;
				case 2: //Allemand
					printf("Gestopppt und zurückgesetzt!\n");
					Hour = 00;
					Minute = 00;
					Second = 00;
					Milli = 00;
					Start = 0;
					Pause = false;
					break;
				case 3: //Français
					printf("Stoppé et réinistialisé!\n");
					Hour = 00;
					Minute = 00;
					Second = 00;
					Milli = 00;
					Start = 0;
					Pause = false;
					break;
				case 5: //Italien
					printf("Fermato e resettato!\n");
					Hour = 00;
					Minute = 00;
					Second = 00;
					Milli = 00;
					Start = 0;
					Pause = false;
					break;
				case 7: //Néerlandais
					printf("Gestopt en gereset!\n");
					Hour = 00;
					Minute = 00;
					Second = 00;
					Milli = 00;
					Start = 0;
					Pause = false;
					break;
				default : //Traduction manquante
					printf("Error: Translation is missing, or something went wrong in the code!\n");
					printf("But the stopwatch sould normally be reseted");
					break;
			}
		}

		//Code to make time time pause. Needs to be tested.
		if (pressed & WPAD_BUTTON_B)
			if (Start > 1)
			{
				Pause = !Pause;
					if (Pause == true)
					{
						printf("Debug Pause\n");
					}

					else
					{
						printf("Debug unpause\n");
					}
			}

		//Credits
		if (pressed & WPAD_BUTTON_MINUS)
			if ( Start > 1)
			{
				switch(language){
				case 1:	//English
					printf("Cannot show the credits because the stopwatch is running.\n");
					break;
				case 2: //German
					printf("Kann die Kredite nicht anzeigen weill die Stopuhr lauuft.\n");
					break;
				case 3: //French
					printf("Les crédits ne peuvent pas être affiché car le chronomètre est allumé.\n");
					break;
				case 5: //Italian
					printf("I crediti non possono essere visualizzati perché il cronometro è acceso.\n");
					break;
				case 7: //Dutch. Translation needed
					printf("Gestopt en gereset!\n");
					break;
				default : //Translation missing
					printf("Error: Translation is missing, or something went wrong in the code!\n");
					printf("But the credits cannot be shown because the timer is running.");
					break;
				}
			}
			else
			{
				switch(language){
				case 1:	//English
					printf("CREDITS\n");
					printf("Code: Ilovemyhouse\n");
					printf("Testing: Ilovemyhouse\n");
					printf("Translation: Some friends on Discord.\n");
					printf("Libraries: libogc - github.com/devkitPro/libogc");
				case 2: //German
					printf("KREDITE\n");
					printf("Kode: Ilovemyhouse\n");
					printf("Testen: Ilovemyhouse\n");
					printf("Uebersetzungen: Freunde auf Discord.\n");
					printf("Bibliotheken: libogc - github.com/devkitPro/libogc");
				case 3: //French
					printf("CRÉDITS\n");
					printf("Code: Ilovemyhouse\n");
					printf("Test: Ilovemyhouse\n");
					printf("Traductions: Des amis sur Discord.\n");
					printf("Librairies: libogc - github.com/devkitPro/libogc");
				case 5: //Italian
					printf("I crediti non possono essere visualizzati perché il cronometro è acceso.\n");
				case 7: //Dutch
					printf("Insert translation.\n");
					break;
				default : //Translation missing
					printf("Error: Translation is missing, or something went wrong in the code!\n");
					printf("CREDITS\n");
					printf("Code: Ilovemyhouse\n");
					printf("Testing: Ilovemyhouse\n");
					printf("Translation: Some friends on Discord.\n");
					printf("Libraries: libogc - github.com/devkitPro/libogc");
					break;
				}
			}

		//Easter Egg
		if ( pressed & WPAD_BUTTON_1 )
			if (pressed & WPAD_BUTTON_2)
				printf("Hello World!\n");

		//Easter Egg 2
		if ( pressed & WPAD_BUTTON_PLUS)
			if (pressed & WPAD_BUTTON_MINUS)
				printf("You found an Easter Egg!\n");

		//Easter Egg 3
		if ( pressed & WPAD_BUTTON_B )
			if (pressed & WPAD_BUTTON_A)
				printf("This text is just 0's & 1's.\n");

		//Refreches screen.
		VIDEO_WaitVSync();
	}
	return 0;
}
