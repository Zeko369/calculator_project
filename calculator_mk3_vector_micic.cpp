		for(int i = 0; i<a.size(); i++)
		{
			if(a[i] == ' '){ continue; }       //spaec
			else if(isNum(a[i]) || a[i] == '.')		   //num
			{ 
				while(isNum(a[i]))
				{
					num[nIter] += a[i] - 48;
					num[nIter] *= 10;
					b += a[i];
					i++;
				}

				num[nIter] /= 10;
				
				if(a[i] == '.')
				{
					b += '.';

					if(!(isNum(a[i-1])))
					{
						num[nIter] = 0;
					}

					i++;
					rem = 0;

					while(isNum(a[i]))
					{
						rem += a[i] - 48;
						rem *= 10;
						b += a[i];
						i++;
					}

				        rem /= 10;

					while(rem > 1){ rem /= 10.0; }

					num[nIter] += rem;
				}

	                        nIter++;
				n_nums++;
			}
		        else				   //op
			{
				b += a[i];

				ops[oIter] = a[i];
				oIter++;
				n_ops++;

				if((a[i] == '+' || a[i] == '-') && highestStep == 0){ highestStep = 1; }
				else if((a[i] == '*' || a[i] == '/') && highestStep < 2){ highestStep = 2; }
				else if((a[i] == '(') && highestStep < 3){ highestStep = 3; }
			}
		}
