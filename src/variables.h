#ifndef _variables_
#define _variables_

extern int 	i, True, False;

extern int		cpu, cputemp, cputype,
				aptget,
				proc, set_process,
				swap,
				set_battery,
				nodata, clocktype, set_calendar, clock_12h,
				nvidia,
				set_hd, hdtype, hdtemp1, hdtemp2, hdtemp3, hdtemp4,
				mpd, rhythmbox, banshee, exaile, cover, covergloobus,
				set_photo,
				pidgin, limit, gmail,
				todo,
				bbcweather, bbccode, set_weather, weatherplus, unit,
				set_network, set_wireless, eth, wlan, ppp,
				logo,
				go2, yp, yc,
				board, nobg,
				argb_value;
				
extern float	board_width, board_height;

extern char 	player[32],
				side[32],
				weather_code[32], imperial[32],
				logo_letter[32],
				user[32], password[32],
				dev1[32], dev2[32], dev3[32], dev4[32];

extern int		cairo_set, shape;

extern const char *datadir;

#define LEN_CHAR 256
#define ARGB_VALUE 180

#endif // #ifndef _variables_

