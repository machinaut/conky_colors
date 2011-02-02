#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conkyrc_default.h"
#include "finddir.h"
#include "translations.h"
#include "themes.h"
#include "variables.h"
#include "utils.h"

void conkyrc_default () {
	
	FILE *fp;
	
	fp = fopenf("%s/conkyrc", "w", tempdir());
	if(fp == 0)
	{
		printf("failed to open %s with write permission.\n", tempdir());
		return;
	}

	const char *forecastdir=finddir("bin/conkyForecast");
	const char *clockdir=finddir("bin/conkyClock");
	const char *forecastconfdir=finddir(".conkyForecast.config");
	const char *templdir=finddir("templates/conkyForecast.template");
	const char *playerdir=finddir("bin/conky%s", player);
	const char *pltempldir=finddir("templates/conkyPlayer.template");
	const char *coverdir=finddir("bin/conkyCover");
	const char *conkyipdir=finddir("bin/conkyIp");

	//Global Setup
	fprintf(fp,"######################\n");
	fprintf(fp,"# - Conky settings - #\n");
	fprintf(fp,"######################\n");
	fprintf(fp,"update_interval 1\n");
	fprintf(fp,"total_run_times 0\n");
	fprintf(fp,"net_avg_samples 1\n");
	fprintf(fp,"cpu_avg_samples 1\n");
	fprintf(fp,"\n");
	fprintf(fp,"imlib_cache_size 0\n");
	fprintf(fp,"double_buffer yes\n");
	fprintf(fp,"no_buffers yes\n");
	fprintf(fp,"\n");
	fprintf(fp,"format_human_readable\n");
	fprintf(fp,"\n");
	fprintf(fp,"#####################\n");
	fprintf(fp,"# - Text settings - #\n");
	fprintf(fp,"#####################\n");
	fprintf(fp,"use_xft yes\n");
	fprintf(fp,"xftfont Droid Sans:size=8\n");
	fprintf(fp,"override_utf8_locale yes\n");
	fprintf(fp,"text_buffer_size 2048\n");
	fprintf(fp,"\n");
	fprintf(fp,"#############################\n");
	fprintf(fp,"# - Window specifications - #\n");
	fprintf(fp,"#############################\n");
	fprintf(fp,"own_window_class Conky\n");
	fprintf(fp,"own_window yes\n");
	if (shiki == True)
		fprintf(fp,"own_window_colour 3C3C3C\n");
	else
		if (shikidust == True)
			fprintf(fp,"own_window_colour 464139\n");
		else
			if (dust == True)
				fprintf(fp,"own_window_colour 2C2B29\n");
	if (set_photo == 1 || set_photo == 2 || cover > 2)
		fprintf(fp,"own_window_type override\n");
	else {
		fprintf(fp,"own_window_type normal\n");
		fprintf(fp, "own_window_argb_visual yes\n");
		fprintf(fp, "own_window_argb_value %d\n", argb_value);
	}
	if ((shiki == True || shikidust == True || dust == True))
		fprintf(fp,"own_window_transparent no\n");
	else
		fprintf(fp,"own_window_transparent yes\n");
	fprintf(fp,"own_window_hints undecorated,below,sticky,skip_taskbar,skip_pager\n");
	fprintf(fp,"\n");
	if(strcmp("left",side) == 0)
		fprintf(fp,"alignment top_left\n");
	else
		fprintf(fp,"alignment top_right\n");
	if (cairo_set == 1)
		fprintf(fp,"gap_x 0\n");
	else
		fprintf(fp,"gap_x 25\n");
	if (shiki == True || shikidust == True || dust == True)
		fprintf(fp,"gap_y 50\n");
	else
		fprintf(fp,"gap_y 40\n");
	fprintf(fp,"minimum_size 182 0\n");
	fprintf(fp,"maximum_width 182\n");
	fprintf(fp,"\n");
	fprintf(fp,"default_bar_size 60 8\n");
	fprintf(fp,"\n");
	fprintf(fp,"#########################\n");
	fprintf(fp,"# - Graphics settings - #\n");
	fprintf(fp,"#########################\n");
	fprintf(fp,"draw_shades no\n");
	if ((shiki == True || shikidust == True || dust == True)) {
		fprintf(fp,"draw_borders yes\n");
		if (dust == True)
			fprintf(fp,"border_width 6\n");
		else
			fprintf(fp,"border_width 1\n");
		if (dust == True)
			fprintf(fp,"border_margin 14\n");
		else
			fprintf(fp,"border_margin 10\n");
		fprintf(fp,"draw_graph_borders yes\n");
		fprintf(fp,"draw_outline no\n");
		fprintf(fp,"\n");
		if (shikidust == True)
			fprintf(fp,"default_color D1CCC4\n");
		else
			if (dust == True)
				fprintf(fp,"default_color 929292\n");
			else
				fprintf(fp,"default_color D8D8D8\n");
	}
	else
		if(custom == True)
			fprintf(fp,"\ndefault_color %s\n", defaultcolor);
		else
			if(elementary == True && dark == True)
				fprintf(fp,"\ndefault_color 2B2B2B\n");
		else
			if(elementary == True)
				fprintf(fp,"\ndefault_color D6D6D6\n");
		else
			if(radiance == True)
				fprintf(fp,"\ndefault_color E2DACB\n");
		else
			if(ambiance == True)
				fprintf(fp,"\ndefault_color 3C3B37\n");
		else
			if(dark == True || alldark == True)
				fprintf(fp,"\ndefault_color 212526\n");
		else
			fprintf(fp,"\ndefault_color cccccc\n");
	fprintf(fp,"\n");
	if ((shiki == True || shikidust == True || dust == True))
		fprintf(fp,"color0 %s\n", color0);
	else
		if (custom == True || radiance == True || ambiance == True || elementary == True)
			fprintf(fp,"color0 %s\n", color0);
		else
			if (dark == True || alldark == True)
				fprintf(fp,"color0 1E1C1A\n");
		else
			fprintf(fp,"color0 white\n");
	if (custom == True || radiance == True || ambiance == True || elementary == True)
		fprintf(fp,"color1 %s\n", color1);
	else
		if (alldark == True)
			fprintf(fp,"color1 1E1C1A\n");
		else
			if (alllight == True)
				fprintf(fp,"color1 white\n");
		else
			fprintf(fp,"color1 %s\n", color1);
	if ((shiki == True || shikidust == True || dust == True)) 
		fprintf(fp,"color2 %s\n", color2);
	else
		if (custom == True || radiance == True || ambiance == True || elementary == True)
			fprintf(fp,"color2 %s\n", color2);
		else
			if (dark == True || alldark == True)
				fprintf(fp,"color2 1E1C1A\n");
		else
			fprintf(fp,"color2 white\n");
	
	fprintf(fp,"\n");
	fprintf(fp,"TEXT\n");

	//System Widget
	fprintf(fp,"${font Droid Sans:style=Bold:size=8}%s $stippled_hr${font}\n", sys);
	fprintf(fp,"##############\n");
	fprintf(fp,"# - SYSTEM - #\n");
	fprintf(fp,"##############\n");
	//Logo
	if (logo == True) {
		fprintf(fp,"${color0}${voffset 6}${font OpenLogos:size=19}%s${font}${color}", logo_letter);
		fprintf(fp,"${goto %d}${voffset -14}Kernel:  ${alignr}${color2}${kernel}${color}\n", go2);
	}
	else {
		fprintf(fp,"${color0}${font Poky:size=15}S${font}${color}");
		fprintf(fp,"${goto %d}${voffset -8}Kernel:  ${alignr}${color2}${kernel}${color}\n", go2);
	}
	fprintf(fp,"${goto %d}%s: ${alignr}${color2}${uptime}${color}\n", go2, uptime);
	//Updates
	if (aptget == True) {
		fprintf(fp,"# |--UPDATES\n");
		fprintf(fp,"${goto %d}%s: ${alignr}${font Droid Sans:style=Bold:size=8}${color1}${execi 360 aptitude search \"~U\" | wc -l | tail}${color}${font} ${color2}%s${color}\n", go2, updates, packages);
	}
	//Gmail without pidgin widget
	if (gmail == True && pidgin == False) {
		fprintf(fp,"# |--GMAIL\n");
		fprintf(fp,"${goto %d}Gmail: ${alignr}${font Droid Sans:style=Bold:size=8}${color0}${execpi 3600 %s/bin/conkyEmail --servertype=IMAP --servername=imap.googlemail.com -u %s -p %s --ssl}${color}${font} %s email(s)\n", go2, finddir("bin/conkyEmail"), user, password, nouve);
	}
	//CPU
	fprintf(fp,"# |--CPU\n");
	if (cpu == 1) {
		fprintf(fp,"${offset 2}${color0}${font Poky:size=16}P${color}${font}${voffset -4}");
		if (cputemp == True) {
			if (unit == True)
				fprintf(fp,"${goto %d}CPU: ${font Droid Sans:style=Bold:size=8}${color1}${cpu cpu1}%%${font} ${alignr}${font Droid Sans:style=Bold:size=8}${color1}${execi 30 sensors -f | grep 'Core 0' | cut -c14-16}°F${color}${font}  ${color2}${cpugraph cpu1 8,50 %s}${color}\n", go2, color3);
			else
				fprintf(fp,"${goto %d}CPU: ${font Droid Sans:style=Bold:size=8}${color1}${cpu cpu1}%%${font} ${alignr}${font Droid Sans:style=Bold:size=8}${color1}${execi 30 sensors | grep 'Core 0' | cut -c15-16}°C${color}${font}  ${color2}${cpugraph cpu1 8,50 %s}${color}\n", go2, color3);
		}
		else
			fprintf(fp,"${goto %d}CPU: ${font Droid Sans:style=Bold:size=8}${color1}${cpu cpu1}%%${color}${font} ${alignr}${color2}${cpugraph cpu1 8,60 %s}${color}\n", go2, color3);
	}
	else {
		fprintf(fp,"${offset 1}${color0}${font Poky:size=16}P${font}${offset -19}${voffset 9}${cpubar cpu0 4,18}${color}${voffset -16}");
		for (i = True; i <= cpu; i++) {
			if (cputemp == True) {
				if (unit == True)
					fprintf(fp,"${goto %d}CPU%d: ${font Droid Sans:style=Bold:size=8}${color1}${cpu cpu%d}%%${font} ${alignr}${font Droid Sans:style=Bold:size=8}${color1}${execi 30 sensors -f | grep 'Core %d' | cut -c14-16}°F${color}${font}  ${color2}${cpugraph cpu%d 8,50 %s}${color}\n", go2, i, i, i-1, i, color3);
				else
					fprintf(fp,"${goto %d}CPU%d: ${font Droid Sans:style=Bold:size=8}${color1}${cpu cpu%d}%%${font} ${alignr}${font Droid Sans:style=Bold:size=8}${color1}${execi 30 sensors | grep 'Core %d' | cut -c15-16}°C${color}${font}  ${color2}${cpugraph cpu%d 8,50 %s}${color}\n", go2, i, i, i-1, i, color3);
			}
			else
				fprintf(fp,"${goto %d}CPU%d: ${font Droid Sans:style=Bold:size=8}${color1}${cpu cpu%d}%%${color}${font} ${alignr}${color2}${cpugraph cpu%d 8,60 %s}${color}\n", go2, i, i, i, color3);
		}
	}
	//Memory
	fprintf(fp,"# |--MEM\n");
	fprintf(fp,"${color0}${font Poky:size=16}M${font}${color}${goto %d}${voffset -7}RAM: ${font Droid Sans:style=Bold:size=8}${color1}$memperc%%${color}${font}\n", go2);
	fprintf(fp,"${offset 1}${voffset 2}${color0}${membar 4,18}${color}${goto %d}${voffset -2}F: ${font Droid Sans:style=Bold:size=8}${color2}${memeasyfree}${color}${font} U: ${font Droid Sans:style=Bold:size=8}${color2}${mem}${color}${font}\n", go2);
	//Swap
	if (swap == True) {
		fprintf(fp,"# |--SWAP\n");
		fprintf(fp,"${voffset 2}${color0}${font Poky:size=14}s${font}${color}${voffset -8}${goto %d}SWAP: ${font Droid Sans:style=Bold:size=8}${color1}${swapperc}%%${color}${font}\n", go2);
		fprintf(fp,"${voffset 4}${offset 1}${color0}${swapbar 4,18}${color}${voffset -4}${goto %d}F: ${font Droid Sans:style=Bold:size=8}${color2}$swapmax${color}${font} U: ${font Droid Sans:style=Bold:size=8}${color2}$swap${color}${font}\n", go2);
	}
	//Battery
	if (set_battery == True) {
		fprintf(fp,"# |--BATTERY\n");
		fprintf(fp,"${color0}${font Poky:size=13}E${font}${color}${goto %d}${voffset -5}%s: ${font Droid Sans:style=Bold:size=8}${color1}${battery_percent BAT0}%%${color}${font} ${alignr}${color2}${battery_bar 8,60 BAT0}${color}\n", go2, battery);
	}
	//Processes
	if (set_process == True) {
		fprintf(fp,"# |--PROC\n");
		fprintf(fp,"${voffset 2}${color0}${font Poky:size=15}a${font}${color}${goto %d}${voffset -10}%s: ${color2}${alignr 13}CPU${alignr}RAM${color}\n", go2, processes);
		for (i = True; i <= proc; i++)
			if (shiki == True || shikidust == True || dust == True)
				fprintf(fp,"${voffset -1}${goto 46}${color2}${top name %d}${color}${font Droid Sans:style=Bold:size=8}${color1} ${goto 127}${top cpu %d}${alignr }${top mem %d}${color}${font}\n", i, i, i);
			else
				fprintf(fp,"${voffset -1}${goto 42}${color2}${top name %d}${color}${font Droid Sans:style=Bold:size=8}${color1} ${goto 124}${top cpu %d}${alignr }${top mem %d}${color}${font}\n", i, i, i);
	}

	//Clock and Calendar Widget
	if (nodata == False) {
		fprintf(fp,"#############\n");
		fprintf(fp,"# - CLOCK - #\n");
		fprintf(fp,"#############\n");
		fprintf(fp,"${voffset 4}${font Droid Sans:style=Bold:size=8}%s $stippled_hr${font}\n", date);
		//Classic Theme
		if (clocktype == 1) {
			fprintf(fp,"${voffset 10}${alignc 55}${font aClock:style=_Hour:size=90}${color2}${execpi 120 %s/bin/conkyClock_h}${color}${font}\n", finddir("bin/conkyClock_h") );
			fprintf(fp,"${voffset -98}${alignc 55}${font aClock:style=_Min:size=90}${color2}${execpi 60 %s/bin/conkyClock_m}${color}${font}\n", finddir("bin/conkyClock_m") );
			fprintf(fp,"${voffset 12}${alignc}${font Droid Sans:style=Bold:size=10}${color1}${time %%H:%%M}${color}${font}${voffset -8}\n");
		}
		//Slim Theme
		else
			if (clocktype == 2) {
				fprintf(fp,"${voffset 20}${alignc 44}${font zoraclockH:size=70}${color2}${execpi 120 %s/bin/conkyClock hour}${color}${font}\n", clockdir );
				fprintf(fp,"${voffset -90}${alignc 64}${font zoraclockM:size=100}${color2}${execpi 60 %s/bin/conkyClock minute}${color}${font}\n", clockdir );
				fprintf(fp,"${voffset 26}${alignc}${font Droid Sans:style=Bold:size=10}${color1}${time %%H:%%M}${color}${font}${voffset -8}\n");
			}
		//Modern Theme
		else
			if (clocktype == 3) {
				fprintf(fp,"${voffset -12}${goto 28}${font Arial Black:size=38}${color2}${time %%H}${color}${font}${voffset -28}${font Droid Sans:style=Bold:size=11}${color2}${time :%%M}${time :%%S}${color}${font}\n");
				fprintf(fp,"${voffset -2}${goto 100}${font Droid Sans:style=Bold:size=8}${color2}${time %%A}${color}${font}\n");
				fprintf(fp,"${goto 100}${time %%d %%b %%Y}\n");
			}
		//Lucky Theme
		else
			if (clocktype == 4) {
				fprintf(fp,"${voffset 4}${goto 32}${font clockfaces:size=40}O${font}\n");
				fprintf(fp,"${voffset -34}${goto 41}${font zoraclockH:size=30}${color2}${execpi 120 %s/bin/conkyClock hour}${color}${font}\n", clockdir);
				fprintf(fp,"${voffset -39}${goto 35}${font zoraclockM:size=40}${color2}${execpi 60 %s/bin/conkyClock minute}${color}${font}\n", clockdir);
				fprintf(fp,"${goto 100}${voffset -40}${font Droid Sans:style=Bold:size=11}${color2}${time %%H}${time :%%M}${time :%%S}${color}${font}\n");
				fprintf(fp,"${goto 100}${voffset -2}${goto 100}${font Droid Sans:style=Bold:size=8}${color2}${time %%A}${color}${font}\n");
				fprintf(fp,"${goto 100}${time %%d %%b %%Y}${voffset 8}\n");
			}
		//Digital Theme
		else
			if (clocktype == 5) {
				fprintf(fp,"${font Digital Readout Thick Upright:size=40}${goto 22}${color2}${time %%k}${voffset -9}:${voffset 9}${time %%M}${goto 130}${color2}${voffset -14}${font Digital Readout Thick Upright:size=24}${goto 130}${color2}${time %%d}${font Digital Readout Thick Upright:size=12}${voffset 14}${goto 130}${color2}${time %%m}${goto 144}${color2}${time %%y}${font}\n");
			}
		//Clock off
		else
			if (clocktype == 6);
		else
			fprintf(fp,"${voffset -10}${alignc 46}${color2}${font Arial Black:size=30}${time %%H:%%M}${font}${color}\n");
		if (clocktype != 3 && clocktype != 4 && clocktype != 5) {
			if (clocktype == 1 || clocktype == 2)
				fprintf(fp,"${voffset 8}${alignc}${time %%d %%B %%Y}\n");
			else
				if (clocktype == 5)
					fprintf(fp,"${voffset 4}${alignc}${time %%d %%B %%Y}\n");
				else
				if (set_calendar > 0)
					fprintf(fp,"${voffset 6}${alignc}${time %%d %%B %%Y}${voffset -6}\n");
				else
					fprintf(fp,"${alignc}${time %%d %%B %%Y}\n");
		}
		//Calendar
		if (set_calendar > 0) {
			fprintf(fp,"################\n");
			fprintf(fp,"# - CALENDAR - #\n");
			fprintf(fp,"################\n");
			if (set_calendar == True)
				fprintf(fp,"${voffset -2}${color0}${font Poky:size=16}D${font}${voffset -8}${font Droid Sans:style=Bold:size=7}${offset -17}${voffset 4}${time %%d}${font}${color}${voffset -1}${font Droid Sans Mono:size=7}${execpi 300 DJS=`date +%%_d`; cal |sed \'2,7!d\'| sed \'/./!d\' | sed \'s/^/${goto 32} /\'| sed \'s/$/ /\' | sed \'s/^/ /\' | sed /\" $DJS \"/s/\" $DJS \"/\" \"\'${font Droid Sans:style=Bold:size=8}${color1}\'\"$DJS\"\'${color}${font Droid Sans Mono:size=7}\'\" \"/}${voffset -1}\n");
			else if (set_calendar == 2) 
				fprintf(fp,"${voffset -2}${color0}${font Poky:size=16}D${font}${voffset -8}${font Droid Sans:style=Bold:size=7}${offset -17}${voffset 4}${time %%d}${font}${color}${font Droid Sans Mono:size=7}${execpi 10800 %s/bin/conkyCalendar}${font}${voffset -14}\n", finddir("bin/conkyCalendar"));
			else
				fprintf(fp,"${voffset -2}${color0}${font Poky:size=16}D${font}${voffset -8}${font Droid Sans:style=Bold:size=7}${offset -17}${voffset 4}${time %%d}${font}${color}${voffset -1}${font Droid Sans Mono:size=7}${execpi 300 DJS=`date +%%_d`; cal -m |sed \'2,7!d\'| sed \'/./!d\' | sed \'s/^/${goto 32} /\'| sed \'s/$/ /\' | sed \'s/^/ /\' | sed /\" $DJS \"/s/\" $DJS \"/\" \"\'${font Droid Sans:style=Bold:size=8}${color1}\'\"$DJS\"\'${color}${font Droid Sans Mono:size=7}\'\" \"/}${voffset -1}\n");
		}
	}

	//Photo Widget
	if (set_photo > 0) {
		int num=num_datadir();
		fprintf(fp,"#############\n");
		fprintf(fp,"# - PHOTO - #\n");
		fprintf(fp,"#############\n");
		fprintf(fp,"# For a working photo widget you need to specify a file or directory in conkyPhoto or conkyPhotoRandom script in ");

		for(unsigned int i=0; i<num; ++i)
		{
			const char *dir=get_datadir(i);
			if(dir[0] != '\0')
				fprintf(fp, " %s/bin", dir);
		}
		fprintf(fp," folders\n");
		fprintf(fp,"${voffset 4}${font Droid Sans:style=Bold:size=8}%s $stippled_hr${font}\n", photo);
		if (set_photo == 1)
			fprintf(fp,"${execi 10800 %s/bin/conkyPhoto}${image /tmp/conkyPhoto.png -s 175x120 -p 4,%d}${voffset 114}\n", finddir("bin/conkyPhoto"), yp);
		else
			fprintf(fp,"${execi 60 %s/bin/conkyPhotoRandom}${image /tmp/conkyPhoto.png -s 175x120 -p 4,%d}${voffset 114}\n", finddir("bin/conkyPhotoRandom"), yp);
	}

	//Rhythmbox/Exaile/Banshee Widget
	if (rhythmbox == True || exaile == True || banshee == True) {
		fprintf(fp,"####################\n");
		fprintf(fp,"# - MEDIA PLAYER - #\n");
		fprintf(fp,"####################\n");
		fprintf(fp,"${voffset 4}${font Droid Sans:style=Bold:size=8}MEDIA PLAYER $stippled_hr${font}\n");
		if (cover > 2)
			fprintf(fp,"${execi 6 %s/bin/conkyCover}", coverdir);
		fprintf(fp,"${execpi 2 %s/bin/conky%s -t %s/templates/conkyPlayer.template}\n", playerdir, player, pltempldir );
	}

	//MPD Widget
	if (mpd == True) {
		fprintf(fp,"###########\n");
		fprintf(fp,"# - MPD - #\n");
		fprintf(fp,"###########\n");
		fprintf(fp,"${voffset 4}${font Droid Sans:style=Bold:size=8}MPD $stippled_hr${font}\n");
		fprintf(fp,"${execpi 2 %s/bin/conkyMPD}\n", finddir("bin/conkyMPD") );
	}

	//CoverGloobus Widget
	if (covergloobus == True) {
		fprintf(fp,"####################\n");
		fprintf(fp,"# - CoverGloobus - #\n");
		fprintf(fp,"####################\n");
		fprintf(fp,"${voffset 4}${font Droid Sans:style=Bold:size=8}MEDIA PLAYER $stippled_hr${font}\n");
		fprintf(fp,"${voffset 80}\n");
	}

	//ToDo
	if (todo == True) {
		fprintf(fp,"############\n");
		fprintf(fp,"# - TODO - #\n");
		fprintf(fp,"############\n");
		fprintf(fp,"# Create a file called ToDo.txt in your home\n");
		fprintf(fp,"${voffset 4}${font Droid Sans:style=Bold:size=8}TO DO $stippled_hr${font}\n");
		fprintf(fp,"${voffset 4}${execpi 20 cat ~/ToDo.txt | sed -n '1,12p' | sed 's/^/${voffset -6}${color0}${font Poky:size=14}A${font}${color}${voffset -3}${goto %d}/'}\n", go2);
	}

	//NVIDIA Widget
	if (nvidia == True) {
		fprintf(fp,"##############\n");
		fprintf(fp,"# - NVIDIA - #\n");
		fprintf(fp,"##############\n");
		fprintf(fp,"${voffset 4}${font Droid Sans:style=Bold:size=8}NVIDIA $stippled_hr${font}\n");
		fprintf(fp,"${color0}${voffset -4}${font Poky:size=17}N${font}${color}");
		fprintf(fp,"${goto %d}${voffset -8}GPU Temp:${alignr}${font Droid Sans:style=Bold:size=8}${color1} ${exec nvidia-settings -q GPUCoreTemp | grep Attribute | cut -d ' ' -f 6 | cut -c 1-2}${font}${color}°C\n", go2);
		fprintf(fp,"${goto %d}GPU Clock:${alignr}${font Droid Sans:style=Bold:size=8}${color1} ${exec nvidia-settings -q GPU2DClockFreqs -t}${font}${color}MHz\n", go2);
		fprintf(fp,"${goto %d}Video RAM:${alignr}${font Droid Sans:style=Bold:size=8}${color1} ${exec nvidia-settings -q VideoRam -t}${font}${color}KiB\n", go2);
		fprintf(fp,"${goto %d}Driver Version:${alignr}${font Droid Sans:style=Bold:size=8}${color1} ${exec nvidia-settings -q NvidiaDriverVersion -t}${font}${color}\n", go2);
	}

	//HD Widget
	if (set_hd == True) {
		fprintf(fp,"##########\n");
		fprintf(fp,"# - HD - #\n");
		fprintf(fp,"##########\n");
		fprintf(fp,"${voffset 4}${font Droid Sans:style=Bold:size=8}%s $stippled_hr${font}\n", hd);
		if (hdtemp1 == True) {
		fprintf(fp,"# |--HDTEMP1\n");
			if (hdtemp2 == True || hdtemp3 == True || hdtemp4 == True)
				if (unit == True)
					fprintf(fp,"  ${voffset 4}${color0}${font Weather:size=15}y${font}${color}${voffset -8}${goto %d}/dev/%s: ${font Droid Sans:style=Bold:size=8}${color1}${execi 120 hddtemp /dev/%s -n --unit=F}°F${color}${font}\n", go2, dev1, dev1);
				else
					fprintf(fp,"  ${voffset 4}${color0}${font Weather:size=15}y${font}${color}${voffset -8}${goto %d}/dev/%s: ${font Droid Sans:style=Bold:size=8}${color1}${execi 120 hddtemp /dev/%s -n --unit=C}°C${color}${font}\n", go2, dev1, dev1);
			else
				if (unit == True)
					fprintf(fp,"  ${voffset 4}${color0}${font Weather:size=15}y${font}${color}${voffset -3}${goto %d}%s: ${font Droid Sans:style=Bold:size=8}${color1}${execi 120 hddtemp /dev/%s -n --unit=F}°F${color}${font}${alignr}${color2}/dev/%s${color}\n", go2, temperature, dev1, dev1);
				else
					fprintf(fp,"  ${voffset 4}${color0}${font Weather:size=15}y${font}${color}${voffset -3}${goto %d}%s: ${font Droid Sans:style=Bold:size=8}${color1}${execi 120 hddtemp /dev/%s -n --unit=C}°C${color}${font}${alignr}${color2}/dev/%s${color}\n", go2, temperature, dev1, dev1);
		}
		if (hdtemp2 == True) {
			fprintf(fp,"# |--HDTEMP2\n");
			if (unit == True)
				fprintf(fp,"${goto %d}/dev/%s: ${font Droid Sans:style=Bold:size=8}${color1}${execi 120 hddtemp /dev/%s -n --unit=F}°F${color}${font}\n", go2, dev2, dev2);
			else
				fprintf(fp,"${goto %d}/dev/%s: ${font Droid Sans:style=Bold:size=8}${color1}${execi 120 hddtemp /dev/%s -n --unit=C}°C${color}${font}\n", go2, dev2, dev2);
		}
		if (hdtemp3 == True) {
			fprintf(fp,"# |--HDTEMP3\n");
			if (unit == True)
				fprintf(fp,"${goto %d}/dev/%s: ${font Droid Sans:style=Bold:size=8}${color1}${execi 120 hddtemp /dev/%s -n --unit=F}°F${color}${font}\n", go2, dev3, dev3);
			else
				fprintf(fp,"${goto %d}/dev/%s: ${font Droid Sans:style=Bold:size=8}${color1}${execi 120 hddtemp /dev/%s -n --unit=C}°C${color}${font}\n", go2, dev3, dev3);
		}
		if (hdtemp4 == True) {
			fprintf(fp,"# |--HDTEMP4\n");
			if (unit == True)
				fprintf(fp,"${goto %d}/dev/%s: ${font Droid Sans:style=Bold:size=8}${color1}${execi 120 hddtemp /dev/%s -n --unit=F}°F${color}${font}\n", go2, dev4, dev4);
			else
				fprintf(fp,"${goto %d}/dev/%s: ${font Droid Sans:style=Bold:size=8}${color1}${execi 120 hddtemp /dev/%s -n --unit=C}°C${color}${font}\n", go2, dev4, dev4);
		}
		if (hdtype == 1)
			fprintf(fp,"${execpi 30 %s/bin/conkyHD1}\n", finddir("bin/conkyHD1") ); //Default Theme
		else
			if (hdtype == 2)
				fprintf(fp,"${execpi 30 %s/bin/conkyHD2}\n", finddir("bin/conkyHD2") ); //Meerkat Theme
			else
				if (hdtype == 3)
					fprintf(fp,"${execpi 30 %s/bin/conkyHD3}\n", finddir("bin/conkyHD3") ); //Mix Theme
			else
				fprintf(fp,"${execpi 30 %s/bin/conkyHD4}\n", finddir("bin/conkyHD4") ); //Simple Theme
	}

	//Network Widget
	if (set_network == True) {
		
		fprintf(fp,"###############\n");
		fprintf(fp,"# - NETWORK - #\n");
		fprintf(fp,"###############\n");
		fprintf(fp,"${voffset 4}${font Droid Sans:style=Bold:size=8}%s $stippled_hr${font}\n", network);
		fprintf(fp,"# |--WLAN%d\n", wlan);
		fprintf(fp,"${if_up wlan%d}\n", wlan);
		fprintf(fp,"${voffset -13}${color0}${font VariShapes Solid:size=14}q${font}${color}${goto %d}${voffset -6}%s: ${font Droid Sans:style=Bold:size=8}${color1}${upspeed wlan%d}${color}${font} ${alignr}${color2}${upspeedgraph wlan%d 8,60 %s}${color}\n", go2, up, wlan, wlan, color3);
		fprintf(fp,"${goto %d}%s: ${font Droid Sans:style=Bold:size=8}${color2}${totalup wlan%d}${color}${font}\n", go2, total, wlan);
		fprintf(fp,"${voffset -2}${color0}${font VariShapes Solid:size=14}Q${font}${color}${goto %d}${voffset -6}%s: ${font Droid Sans:style=Bold:size=8}${color1}${downspeed wlan%d}${color}${font} ${alignr}${color2}${downspeedgraph wlan%d 8,60 %s}${color}\n", go2, down, wlan, wlan, color3);
		fprintf(fp,"${goto %d}%s: ${font Droid Sans:style=Bold:size=8}${color2}${totaldown wlan%d}${color}${font}\n", go2, total, wlan);
		fprintf(fp,"${voffset -2}${color0}${font Poky:size=14}Y${font}${color}${goto %d} ${voffset -2}%s: ${font Droid Sans:style=Bold:size=8}${color1}${wireless_link_qual wlan%d}%%${color}${font} ${alignr}${color2}${wireless_link_bar 8,60 wlan%d}${color}\n", go2, signal, wlan, wlan);
		fprintf(fp,"${voffset 4}${color0}${font Poky:size=13}w${font}${color}${goto %d}${voffset -8}%s: ${alignr}${color2}${addr wlan%d}${color}\n", go2, localip, wlan);
		fprintf(fp,"${goto %d}%s: ${alignr}${color2}${execi 10800 %s/bin/conkyIp}${color}\n", go2, publicip, conkyipdir );
		fprintf(fp,"# |--ETH%d\n", eth);
		fprintf(fp,"${else}${if_up eth%d}\n", eth);
		fprintf(fp,"${voffset -13}${color0}${font VariShapes Solid:size=14}q${font}${color}${goto %d}${voffset -6}%s: ${font Droid Sans:style=Bold:size=8}${color1}${upspeed eth%d}${color}${font} ${alignr}${color2}${upspeedgraph eth%d 8,60 %s}${color}\n", go2, up, eth, eth, color3);
		fprintf(fp,"${goto %d}%s: ${font Droid Sans:style=Bold:size=8}${color2}${totalup eth%d}${color}${font}\n", go2, total, eth);
		fprintf(fp,"${voffset -2}${color0}${font VariShapes Solid:size=14}Q${font}${color}${goto %d}${voffset -6}%s: ${font Droid Sans:style=Bold:size=8}${color1}${downspeed eth%d}${color}${font} ${alignr}${color2}${downspeedgraph eth%d 8,60 %s}${color}\n", go2, down, eth, eth, color3);
		fprintf(fp,"${goto %d}%s: ${font Droid Sans:style=Bold:size=8}${color2}${totaldown eth%d}${color}${font}\n", go2, total, eth);
		fprintf(fp,"${voffset -2}${color0}${font Poky:size=13}w${font}${color}${goto %d}${voffset -4}%s: ${alignr}${color2}${addr eth%d}${color}\n", go2, localip, eth);
		fprintf(fp,"${goto %d}%s: ${alignr}${color2}${execi 10800 %s/bin/conkyIp}${color}\n", go2, publicip, conkyipdir);
		fprintf(fp,"# |--PPP%d\n", ppp);
		fprintf(fp,"${else}${if_up ppp%d}\n", ppp);
		fprintf(fp,"${voffset -13}${color0}${font VariShapes Solid:size=14}q${font}${color}${goto %d}${voffset -6}%s: ${font Droid Sans:style=Bold:size=8}${color1}${upspeed ppp%d}${color}${font} ${alignr}${color2}${upspeedgraph ppp%d 8,60 %s}${color}\n", go2, up, ppp, ppp, color3);
		fprintf(fp,"${goto %d}%s: ${font Droid Sans:style=Bold:size=8}${color2}${totalup ppp%d}${color}${font}\n", go2, total, ppp);
		fprintf(fp,"${voffset -2}${color0}${font VariShapes Solid:size=14}Q${font}${color}${goto %d}${voffset -6}%s: ${font Droid Sans:style=Bold:size=8}${color1}${downspeed ppp%d}${color}${font} ${alignr}${color2}${downspeedgraph ppp%d 8,60 %s}${color}\n", go2, down, ppp, ppp, color3);
		fprintf(fp,"${goto %d}%s: ${font Droid Sans:style=Bold:size=8}${color2}${totaldown ppp%d}${color}${font}\n", go2, total, ppp);
		fprintf(fp,"${voffset -2}${color0}${font Poky:size=13}w${font}${color}${goto %d}${voffset -4}%s: ${alignr}${color2}${addr ppp%d}${color}\n", go2, localip, ppp);
		fprintf(fp,"${else}${voffset 4}${color0}${font PizzaDude Bullets:size=12}4${font}${color}${goto %d}%s${voffset 14}${endif}${endif}${endif}\n", go2, nonet);
	}

	//Pidgin Widget
	if (pidgin == True) {
		fprintf(fp,"##############\n");
		fprintf(fp,"# - PIDGIN - #\n");
		fprintf(fp,"##############\n");
		fprintf(fp,"${voffset 4}${font Droid Sans:style=Bold:size=8}PIDGIN $stippled_hr${font}${if_running pidgin}\n");
		if (gmail == True)
			fprintf(fp,"${voffset -8}${color0}${font Martin Vogel's Symbols:size=19}B${font}${color}${goto %d}Gmail: ${alignr}${font Droid Sans:style=Bold:size=8}${color0}${execpi 3600 %s/bin/conkyEmail --servertype=IMAP --servername=imap.googlemail.com -u %s -p %s --ssl}${color}${font} %s email(s)\n", go2, finddir("bin/conkyEmail"), user, password, nouve);
		fprintf(fp,"${voffset 4}${execpi 10 %s/bin/conkyPidgin -o -s -l %d}${else}\n", finddir("bin/conkyPidgin"), limit);
		fprintf(fp,"${voffset 4}${color0}${font PizzaDude Bullets:size=12}4${font}${color}${goto %d}%s${endif}\n\n", go2,nopidgin);
	}

	//Weather Widget
	if (set_weather == True) {
		fprintf(fp,"###############\n");
		fprintf(fp,"# - WEATHER - #\n");
		fprintf(fp,"###############\n");
		fprintf(fp,"# For a working weather script you NEED to define, in a user specific config file, a partner id and registration code for the weather.com xoap service. For this purpose copy .conkyForecast.config in %s folder to your home and setup as required.\n", forecastconfdir);
		fprintf(fp,"# http://www.weather.com/services/xmloap.html\n");
		if (set_network == True)
			fprintf(fp,"${voffset -8}${font Droid Sans:style=Bold:size=8}%s $stippled_hr${font}\n", Weather);
		else
			fprintf(fp,"${voffset 4}${font Droid Sans:style=Bold:size=8}%s $stippled_hr${font}\n", Weather);
		fprintf(fp,"# |--WLAN%d\n", wlan);
		fprintf(fp,"${if_up wlan%d}\n", wlan);
		fprintf(fp,"${execpi 10800 %s/bin/conkyForecast --location=%s%s -t %s/templates/conkyForecast.template}\n", forecastdir, weather_code, imperial, templdir );
		fprintf(fp,"# |--ETH%d\n", eth);
		fprintf(fp,"${else}${if_up eth%d}\n", eth);
		fprintf(fp,"${execpi 10800 %s/bin/conkyForecast --location=%s%s -t %s/templates/conkyForecast.template}\n", forecastdir, weather_code, imperial, templdir );
		fprintf(fp,"# |--PPP%d\n", ppp);
		fprintf(fp,"${else}${if_up ppp%d}\n", ppp);
		fprintf(fp,"${execpi 10800 %s/bin/conkyForecast --location=%s%s -t %s/templates/conkyForecast.template}\n", forecastdir, weather_code, imperial, templdir);
		fprintf(fp,"${else}");
		fprintf(fp,"${voffset 4}${color0}${font PizzaDude Bullets:size=12}4${font}${color}${goto %d}%s${voffset 14}${endif}${endif}${endif}\n", go2,noweather);
	} else
		if (set_weather == 2) {
			fprintf(fp,"###############\n");
			fprintf(fp,"# - WEATHER - #\n");
			fprintf(fp,"###############\n");
			fprintf(fp,"# For a working weather script you NEED to define, in a user specific config file, a partner id and registration code for the weather.com xoap service. For this purpose copy .conkyForecast.config in %s folder to your home and setup as required.\n", forecastconfdir);
			fprintf(fp,"# http://www.weather.com/services/xmloap.html\n");
			if (set_network == True)
				fprintf(fp,"${voffset -8}${font Droid Sans:style=Bold:size=8}%s $stippled_hr${font}\n", Weather);
			else
				fprintf(fp,"${voffset 4}${font Droid Sans:style=Bold:size=8}%s $stippled_hr${font}\n", Weather);
				fprintf(fp,"${goto 12}${voffset 4}${color0}${font Weather:size=24}y${font}${color}\n");
				fprintf(fp,"${voffset -29}${goto %d}%s: ${font Droid Sans:style=Bold:size=8}${color1}${execpi 10800 %s/bin/conkyForecast --location=%s%s --datatype=HT}${color}${font}\n", go2, temperature, forecastdir, weather_code, imperial);
				fprintf(fp,"${goto %d}${voffset -2}${color0}${font VariShapes Solid:size=8}q${font}${color}${font Droid Sans:style=Bold:size=8}${color2}${execpi 10800 %s/bin/conkyForecast --location=%s%s --datatype=HT --startday=1}${color}${font} ${voffset -2}${color0}${font VariShapes Solid:size=8}Q${font}${voffset -1}${color}${font Droid Sans:style=Bold:size=8}${color2}${execpi 10800 %s/bin/conkyForecast --location=%s%s --datatype=LT --startday=1}${color}${font}\n", go2, forecastdir, weather_code, imperial, forecastdir, weather_code, imperial);
				fprintf(fp,"${goto %d}%s: ${font Droid Sans:style=Bold:size=8}${color1}${execpi 10800 %s/bin/conkyForecast --datatype=HM}${color}${font}${alignr}${color2}${execbar %s/bin/conkyForecast --location=%s%s --datatype=HM}%%${color}${font}\n", go2, humidity, forecastdir, forecastdir, weather_code, imperial);

		}

	//BBCWeather Widget
	if (bbcweather == True) {
		fprintf(fp,"##################\n");
		fprintf(fp,"# - BBCWEATHER - #\n");
		fprintf(fp,"##################\n");
		fprintf(fp,"# http://news.bbc.co.uk/weather/\n");
		if (set_network == True)
			fprintf(fp,"${voffset -8}${font Droid Sans:style=Bold:size=8}%s $stippled_hr${font}\n", Weather);
		else
			fprintf(fp,"${voffset 4}${font Droid Sans:style=Bold:size=8}%s $stippled_hr${font}\n", Weather);

		if (unit == True) {
			fprintf(fp,"${goto 12}${voffset 4}${color0}${font Weather:size=24}y${font}${color}\n");
			fprintf(fp,"${voffset -29}${goto %d}%s: ${font Droid Sans:style=Bold:size=8}${color1}${execi 600 curl -s --connect-timeout 30 \"http://newsrss.bbc.co.uk/weather/forecast/%d/ObservationsRSS.xml\" | sed -n '/Temperature/p' | sed -e 's/&#xB0;/ /g' | sed -e 's/&#37;/%%/g' | sed 's/^.*Temperature: [0-9]* C (//' | sed 's/ F.*$//'}°F${color}${font}\n", go2, temperature, bbccode);
			fprintf(fp,"${goto %d}${voffset -2}${color0}${font VariShapes Solid:size=8}q${font}${color}${font Droid Sans:style=Bold:size=8}${color1}${execi 600 curl -s --connect-timeout 30 \"http://newsrss.bbc.co.uk/weather/forecast/%d/Next3DaysRSS.xml\" | sed -n '/Max Temp/p' | sed '2!d' | sed -e 's/&#xB0;/ /g' | sed -e 's/&#37;/%%/g' | sed 's/^.*Max Temp: [0-9]* C (//' | sed 's/ F.*$//'}°F${color}${font}  ${voffset -2}${color0}${font VariShapes Solid:size=8}Q${font}${color}${voffset -1}${font Droid Sans:style=Bold:size=8}${color1}${execi 600 curl -s --connect-timeout 30 \"http://newsrss.bbc.co.uk/weather/forecast/%d/Next3DaysRSS.xml\" | sed -n '/Max Temp/p' | sed '2!d' | sed -e 's/&#xB0;/ /g' | sed -e 's/&#37;/%%/g' | sed 's/^.*Min Temp: [0-9]* C (//' | sed 's/ F.*$//'}°F${color}${font}\n", go2, bbccode, bbccode);
			fprintf(fp,"${goto %d}%s: ${font Droid Sans:style=Bold:size=8}${color1}${execi 600 curl -s --connect-timeout 30 \"http://newsrss.bbc.co.uk/weather/forecast/%d/Next3DaysRSS.xml\" | sed -n '/Max Temp/p' | sed '2!d' | sed -e 's/&#xB0;/ /g' | sed -e 's/&#37;/%%/g' | sed 's/<[^>]*>//g' | sed 's/^.*Humidity: //' | sed 's/%%.*$//'}%%${color}${font}${alignr}${color2}${execbar curl -s --connect-timeout 30 \"http://newsrss.bbc.co.uk/weather/forecast/%d/Next3DaysRSS.xml\" | sed -n '/Max Temp/p' | sed '2!d' | sed -e 's/&#xB0;/ /g' | sed -e 's/&#37;/%%/g' | sed 's/<[^>]*>//g' | sed 's/^.*Humidity: //' | sed 's/%%.*$//'}%%${color}${font}\n", go2, humidity, bbccode, bbccode);
		}
		else {
			fprintf(fp,"${goto 12}${voffset 4}${color0}${font Weather:size=24}y${font}${color}\n");
			fprintf(fp,"${voffset -29}${goto %d}%s: ${font Droid Sans:style=Bold:size=8}${color1}${execi 600 curl -s --connect-timeout 30 \"http://newsrss.bbc.co.uk/weather/forecast/%d/ObservationsRSS.xml\" | sed -n '/Temperature/p' | sed -e 's/&#xB0;/ /g' | sed -e 's/&#37;/%%/g' | sed 's/^.*Temperature: //' | sed 's/ C.*$//'}°C${color}${font}\n", go2, temperature, bbccode);
			fprintf(fp,"${goto %d}${voffset -2}${color0}${font VariShapes Solid:size=8}q${font}${color}${color2}${execi 600 curl -s --connect-timeout 30 \"http://newsrss.bbc.co.uk/weather/forecast/%d/Next3DaysRSS.xml\" | sed -n '/Max Temp/p' | sed '2!d' | sed -e 's/&#xB0;/ /g' | sed -e 's/&#37;/%%/g' | sed 's/<[^>]*>//g' | sed 's/^.*Max Temp: //' | sed 's/ C.*$//'}°C${color} ${voffset -2}${color0}${font VariShapes Solid:size=8}Q${font}${voffset -1}${color}${color2}${execi 600 curl -s --connect-timeout 30 \"http://newsrss.bbc.co.uk/weather/forecast/%d/Next3DaysRSS.xml\" | sed -n '/Max Temp/p' | sed '2!d' | sed -e 's/&#xB0;/ /g' | sed -e 's/&#37;/%%/g' | sed 's/<[^>]*>//g' | sed 's/^.*Min Temp: //' | sed 's/ C.*$//'}°C${color}\n", go2, bbccode, bbccode);
			fprintf(fp,"${goto %d}%s: ${font Droid Sans:style=Bold:size=8}${color1}${execi 600 curl -s --connect-timeout 30 \"http://newsrss.bbc.co.uk/weather/forecast/%d/Next3DaysRSS.xml\" | sed -n '/Max Temp/p' | sed '2!d' | sed -e 's/&#xB0;/ /g' | sed -e 's/&#37;/%%/g' | sed 's/<[^>]*>//g' | sed 's/^.*Humidity: //' | sed 's/%%.*$//'}%%${color}${font}${alignr}${color2}${execbar curl -s --connect-timeout 30 \"http://newsrss.bbc.co.uk/weather/forecast/%d/Next3DaysRSS.xml\" | sed -n '/Max Temp/p' | sed '2!d' | sed -e 's/&#xB0;/ /g' | sed -e 's/&#37;/%%/g' | sed 's/<[^>]*>//g' | sed 's/^.*Humidity: //' | sed 's/%%.*$//'}%%${color}${font}\n", go2, humidity, bbccode, bbccode);
		}
	}
	if ((shiki == True || shikidust == True || dust == True)) {
		fprintf(fp,"# Ajust this vertial offset to math conky height with your screem and options\n");
		fprintf(fp,"${voffset -75}\n");
	}

	fclose(fp);
}

