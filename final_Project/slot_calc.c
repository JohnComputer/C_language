int slot_calc(int(* slot)[10],int bet){
	int num = 0;

	num = bet;
	if (slot[0][1] == slot[1][1] && slot[1][1] == slot[2][1]) {
		switch (slot[0][1]) {
		case 1:
			num *= 15;	// 6.4%
			break;
		case 2:
			num *= 45;	// 2.7%
			break;
		case 3:
			num *= 100; // 0.8%
			break;
		case 4:
			num *= 1000; // 0.1%
			break;
		}
	}
	else {
		num *= -1;
	}
	return num;
}