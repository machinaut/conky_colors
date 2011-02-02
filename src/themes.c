#define _ISOC99_SOURCE // for snprintf
#include <string.h>
#include <stdio.h>
#include "themes.h"
#include "variables.h"

int 	shiki=0, shikidust=0, dust=0, radiance=0, ambiance=0, elementary=0, custom=0,
		dark=0, alldark=0, alllight=0;

char 	theme[31],
		defaultcolor[31],
		color0[31],
		color1[31],
		color2[31],
		color3[31];

//Themes
void themes () {
	if(strcmp("gnome-brave",theme) == 0) {
		snprintf(color1, 31, "3465A4");
		if (alldark == True)
			snprintf(color3, 31, "1E1C1A 1E1C1A");
		else
			if (alllight == True)
				snprintf(color3, 31, "white white");
			else
				snprintf(color3, 31, "204A87 3465A4");
	}
	else
		if(strcmp("gnome-dust",theme) == 0) {
			snprintf(color1, 31, "906E4C");
		if (alldark == True)
			snprintf(color3, 31, "1E1C1A 1E1C1A");
		else
			if (alllight == True)
				snprintf(color3, 31, "white white");
			else
				snprintf(color3, 31, "745536 906E4C");
		}
	else
		if(strcmp("gnome-illustrious",theme) == 0) {
			snprintf(color1, 31, "dc6472");
		if (alldark == True)
			snprintf(color3, 31, "1E1C1A 1E1C1A");
		else
			if (alllight == True)
				snprintf(color3, 31, "white white");
			else
				snprintf(color3, 31, "C6464B DC6472");
		}
	else
		if(strcmp("gnome-noble",theme) == 0) {
			snprintf(color1, 31, "77507b");
		if (alldark == True)
			snprintf(color3, 31, "1E1C1A 1E1C1A");
		else
			if (alllight == True)
				snprintf(color3, 31, "white white");
			else
				snprintf(color3, 31, "5C3566 77507B");
		}
	else
		if(strcmp("gnome-wine",theme) == 0) {
			snprintf(color1, 31, "C22F2F");
		if (alldark == True)
			snprintf(color3, 31, "1E1C1A 1E1C1A");
		else
			if (alllight == True)
				snprintf(color3, 31, "white white");
			else
				snprintf(color3, 31, "A40000 C22F2F");
		}
	else
		if(strcmp("gnome-wise",theme) == 0) {
			snprintf(color1, 31, "709937");
		if (alldark == True)
			snprintf(color3, 31, "1E1C1A 1E1C1A");
		else
			if (alllight == True)
				snprintf(color3, 31, "white white");
			else
				snprintf(color3, 31, "51751E 709937");
		}
	else
		if(strcmp("gnome-carbonite",theme) == 0) {
			snprintf(color1, 31, "555753");
		if (alldark == True)
			snprintf(color3, 31, "1E1C1A 1E1C1A");
		else
			if (alllight == True)
				snprintf(color3, 31, "white white");
			else
				snprintf(color3, 31, "2E3436 555753");
		}
	else
		if(strcmp("gnome-tribute",theme) == 0) {
			snprintf(color1, 31, "9C9E8A");
		if (alldark == True)
			snprintf(color3, 31, "1E1C1A 1E1C1A");
		else
			if (alllight == True)
				snprintf(color3, 31, "white white");
			else
				snprintf(color3, 31, "7D7E60 9C9E8A");
		}
	else
		if(strcmp("ambiance",theme) == 0) {
			snprintf(color0, 31, "292927");
			snprintf(color1, 31, "C6B9A6");
			snprintf(color2, 31, "292927");
			snprintf(color3, 31, "C6B9A6 C6B9A6");
		}
	else
		if(strcmp("radiance",theme) == 0) {
			snprintf(color0, 31, "F0EBE2");
			snprintf(color1, 31, "F56F6E");
			snprintf(color2, 31, "E6E6E6");
			snprintf(color3, 31, "CD646B F56F6E");
		}
	else
		if(strcmp("elementary",theme) == 0) {
			snprintf(color0, 31, "F2F2F2");
			snprintf(color1, 31, "7296BB");
			snprintf(color2, 31, "FFFFFF");
			snprintf(color3, 31, "7296BB 7296BB");
		}
	else
		if(strcmp("shiki-brave",theme) == 0) {
			snprintf(color0, 31, "E6E6E6");
			snprintf(color1, 31, "3465A4");
			snprintf(color2, 31, "E6E6E6");
			snprintf(color3, 31, "204A87 3465A4");
		}
	else
		if(strcmp("shiki-dust",theme) == 0) {
			snprintf(color0, 31, "E6E6E6");
			snprintf(color1, 31, "906E4C");
			snprintf(color2, 31, "E6E6E6");
			snprintf(color3, 31, "745536 906E4C");
		}
	else
		if(strcmp("shiki-human",theme) == 0) {
			snprintf(color0, 31, "E6E6E6");
			snprintf(color1, 31, "E07A1F");
			snprintf(color2, 31, "E6E6E6");
			snprintf(color3, 31, "CE5C00 E07A1F");
		}
	else
		if(strcmp("shiki-illustrious",theme) == 0) {
			snprintf(color0, 31, "E6E6E6");
			snprintf(color1, 31, "dc6472");
			snprintf(color2, 31, "E6E6E6");
			snprintf(color3, 31, "C6464B DC6472");
		}
	else
		if(strcmp("shiki-noble",theme) == 0) {
			snprintf(color0, 31, "E6E6E6");
			snprintf(color1, 31, "77507b");
			snprintf(color2, 31, "E6E6E6");
			snprintf(color3, 31, "5C3566 77507B");
		}
	else
		if(strcmp("shiki-wine",theme) == 0) {
			snprintf(color0, 31, "E6E6E6");
			snprintf(color1, 31, "C22F2F");
			snprintf(color2, 31, "E6E6E6");
			snprintf(color3, 31, "A40000 C22F2F");
		}
	else
		if(strcmp("shiki-wise",theme) == 0) {
			snprintf(color0, 31, "E6E6E6");
			snprintf(color1, 31, "709937");
			snprintf(color2, 31, "E6E6E6");
			snprintf(color3, 31, "51751E 709937");
		}
	else
		if(strcmp("dust",theme) == 0) {
			snprintf(color0, 31, "E6E6E6");
			snprintf(color1, 31, "AD946F");
			snprintf(color2, 31, "E6E6E6");
			snprintf(color3, 31, "977951 AD946F");
		}
	else
		if(custom == True)
			snprintf(color3, 31, color1);
	else {
		snprintf(color1, 31, "E07A1F");
		if (alldark == True)
			snprintf(color3, 31, "1E1C1A 1E1C1A");
		else
			if (alllight == True)
				snprintf(color3, 31, "white white");
			else
				snprintf(color3, 31, "CE5C00 E07A1F");
	}
}

