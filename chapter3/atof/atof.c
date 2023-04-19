#include <ctype.h>

/* myatof: convert string s into double number */
double myatof(char s[]) {
	
	double man_val, man_power, exp;
	int i, man_sign, exp_positive, exp_power;
	
	for (i = 0; isspace(s[i]); i++)
		;

	man_sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	for (man_val = 0.0; isdigit(s[i]); i++)
		man_val = man_val * 10.0 + s[i] - '0';
	if (s[i] == '.')
		i++;
	for (man_power = 1.0; isdigit(s[i]); i++) {
		man_val = 10.0 * man_val + s[i] - '0';
		man_power *= 10;
	}
	
	if (tolower(s[i]) == 'e')
		i++;

	exp_positive = (s[i] != '-') ? 1 : 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	for (exp_power = 0; isdigit(s[i]); i++)
		exp_power = exp_power * 10 + s[i] - '0';
	for (exp = 1.0; exp_power > 0; exp_power--)
		if (exp_positive)
			exp *= 10;
		else
			exp /= 10;

	return man_sign * man_val / man_power * exp;
}

