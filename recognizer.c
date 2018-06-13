#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "header.h"

void parse_unigram() {
	FILE *uni;
	char input_string[30];
    float input_value;
    uni = fopen("unigram.txt", "r");
    for (int i = 0; i < 12; i++) {
        if (fscanf(uni, "%s %f", &input_string, &input_value)) unigram[i] = input_value;
    }
	fclose(uni);	
}

void parse_bigram() {
    FILE *bi;
    char input_string[30];
    float input_value;
    bi = fopen("bigram.txt", "r");
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if ((i == 0 && j == 0) || (i == 5 && j == 11) || (i == 11 && j == 5)) bigram[i][j] = 0;
			else {
				if (fscanf(bi, "%s %s %f", &input_string, &input_string, &input_value)) bigram[i][j] = input_value;
			}
		}
	}
	fclose(bi);    
}

void get_trans_mat () {
  for (int i = 0; i < TRANS_DIMENSION; i++) 
    for (int j = 0; j < TRANS_DIMENSION; j++) 
      t[i][j] = INF; //초기화
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 2; k++)
        if (phones[0].tp[i+1][j+1] != 0) t[ph_f[k]+i][ph_f[k]+j] = log(phones[0].tp[i+1][j+1]); //for phoneme f
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 1; k++)
        if (phones[1].tp[i+1][j+1] != 0) t[ph_k[k]+i][ph_k[k]+j] = log(phones[1].tp[i+1][j+1]); //for phoneme k 
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++)
        if (phones[2].tp[i+1][j+1] != 0) t[ph_n[k]+i][ph_n[k]+j] = log(phones[2].tp[i+1][j+1]); //for phoneme n
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++)
        if (phones[3].tp[i+1][j+1] != 0) t[ph_r[k]+i][ph_r[k]+j] = log(phones[3].tp[i+1][j+1]); //for phoneme r
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 3; k++)
        if (phones[4].tp[i+1][j+1] != 0) t[ph_s[k]+i][ph_s[k]+j] = log(phones[4].tp[i+1][j+1]); //for phoneme s
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 2; k++)
        if (phones[5].tp[i+1][j+1] != 0) t[ph_t[k]+i][ph_t[k]+j] = log(phones[5].tp[i+1][j+1]); //for phoneme t
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 2; k++)
        if (phones[6].tp[i+1][j+1] != 0) t[ph_v[k]+i][ph_v[k]+j] = log(phones[6].tp[i+1][j+1]); //for phoneme v
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 1; k++)
        if (phones[7].tp[i+1][j+1] != 0) t[ph_w[k]+i][ph_w[k]+j] = log(phones[7].tp[i+1][j+1]); //for phoneme w
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 2; k++)
        if (phones[8].tp[i+1][j+1] != 0) t[ph_z[k]+i][ph_z[k]+j] = log(phones[8].tp[i+1][j+1]); //for phoneme z
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 2; k++)
        if (phones[9].tp[i+1][j+1] != 0) t[ph_ah[k]+i][ph_ah[k]+j] = log(phones[9].tp[i+1][j+1]); //for phoneme ah
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 1; k++)
        if (phones[10].tp[i+1][j+1] != 0) t[ph_ao[k]+i][ph_ao[k]+j] = log(phones[10].tp[i+1][j+1]); //for phoneme ao
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 2; k++)
        if (phones[11].tp[i+1][j+1] != 0) t[ph_ay[k]+i][ph_ay[k]+j] = log(phones[11].tp[i+1][j+1]); //for phoneme ay
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 1; k++)
        if (phones[12].tp[i+1][j+1] != 0) t[ph_eh[k]+i][ph_eh[k]+j] = log(phones[12].tp[i+1][j+1]); //for phoneme eh
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 1; k++)
        if (phones[13].tp[i+1][j+1] != 0) t[ph_ey[k]+i][ph_ey[k]+j] = log(phones[13].tp[i+1][j+1]); //for phoneme ey
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 2; k++)
        if (phones[14].tp[i+1][j+1] != 0) t[ph_ih[k]+i][ph_ih[k]+j] = log(phones[14].tp[i+1][j+1]); //for phoneme ih
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 2; k++)
        if (phones[15].tp[i+1][j+1] != 0) t[ph_iy[k]+i][ph_iy[k]+j] = log(phones[15].tp[i+1][j+1]); //for phoneme iy
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 3; k++)
        if (phones[16].tp[i+1][j+1] != 0) t[ph_ow[k]+i][ph_ow[k]+j] = log(phones[16].tp[i+1][j+1]); //for phoneme ow
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 1; k++)
        if (phones[17].tp[i+1][j+1] != 0) t[ph_th[k]+i][ph_th[k]+j] = log(phones[17].tp[i+1][j+1]); //for phoneme th
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 1; k++)
        if (phones[18].tp[i+1][j+1] != 0) t[ph_uw[k]+i][ph_uw[k]+j] = log(phones[18].tp[i+1][j+1]); //for phoneme uw
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 1; k++)
        if (phones[19].tp[i+1][j+1] != 0) t[ph_sil[k]+i][ph_sil[k]+j] = log(phones[19].tp[i+1][j+1]); //for phoneme sil
  for (int i = 0; i < 12; i++) t[ph_sp[i]][ph_sp[i]] = log(phones[20].tp[1][1]); 
	for (int i = 0; i <12; i++) t[0][ph_start_index[i]] = log(unigram[i]); //선행 없을 때 tp
  t[0][ph_start_index[12]] = log(unigram[11]); //zero 두 개 중 뒤 zero 확률도 넣어주기
  for (int i = 0; i < 11; i++) t[3][ph_start_index[i+1]] = log(phones[19].tp[3][4]) + log(unigram[i+1]); //s to words
  t[3][ph_start_index[12]] = log(phones[19].tp[3][4]) + log(unigram[11]); //left s to words(index 12, zero 2th)
  for (int i = 0; i < 11; i++) 
    for (int j = 0; j < 11; j++) 
      if (bigram[i+1][j+1] != 0) t[ph_sp[i]-1][ph_start_index[j+1]] = log(phones[ph_end_ph[i]].tp[3][4]) + log(unigram[j+1]) + log(phones[20].tp[0][2]); //단어 끝 -> 단어
  for (int i = 0; i < 11; i++)
    for (int j = 0; j < 11; j++)
      if (bigram[i+1][j+1] != 0) t[ph_sp[i]][ph_start_index[j+1]] = log(phones[20].tp[1][2]) + log(unigram[j+1]); //sp -> 단어
  for (int i = 0; i < 11; i++) {
    if (bigram[11][i+1] != 0) t[ph_end_index[11]][ph_start_index[i+1]] = log(phones[16].tp[3][4]) + log(unigram[i+1]) + log(phones[20].tp[0][2]);
    if (bigram[i+1][11] != 0) t[ph_sp[i]-1][ph_start_index[12]] = log(phones[ph_end_ph[i]].tp[3][4]) + log(unigram[11]) + log(phones[20].tp[0][2]);
  } //두번째 0 
  for (int i = 0; i < 11; i++) {
    if (bigram[11][i+1] != 0) t[126][ph_start_index[i+1]] = log(phones[20].tp[1][2]) + log(unigram[i+1]);
    if (bigram[i+1][11] != 0) t[ph_sp[i]][ph_start_index[12]] = log(phones[20].tp[1][2]) + log(unigram[11]);
   } //두번째 0
  t[ph_end_index[11]][ph_start_index[12]] = log(phones[16].tp[3][4]) + log(phones[20].tp[0][2]) + log(unigram[11]);
  t[126][ph_start_index[12]] = log(phones[20].tp[1][2]) + log(unigram[11]);
  t[ph_end_index[11]][1] = log(phones[16].tp[3][4]) + log(phones[20].tp[0][2]) + log(unigram[0]); 
  t[126][1] = log(phones[20].tp[1][2]) + log(unigram[0]);
  for (int i = 0; i < 11; i++) t[ph_sp[i] - 1][1] = log(phones[ph_end_ph[i]].tp[3][4]) + log(unigram[0]) + log(phones[20].tp[0][2]); //단어 끝 -> 단어
  for (int i = 0; i < 12; i++) t[ph_sp[i] - 1][ph_sp[i]] = log(phones[20].tp[0][1]) + log(phones[ph_end_ph[i]].tp[3][4]); 
} //bigram보다 unigram 사용시 정확도가 더 높아서..unigram 사용

void calculate_prob (int i) {
  for (int j = 0; j < TRANS_DIMENSION; j++) { 
	  float max = INF;
		float result_flag = 0;
		for (int k = 0; k < 10; k++){
			pd_v[k] = log(phones[ph_index[j]].state[st_index[j]].pdf[k].weight);
			for (int l = 0; l < N_DIMENSION; l++){
                float variance = phones[ph_index[j]].state[st_index[j]].pdf[k].var[l];
                float mu = phones[ph_index[j]].state[st_index[j]].pdf[k].mean[l];
                float x_minus_mu = (float)(input_vec[i][l] - mu); 
				pd_v[k] -= log(sqrt(variance));
				pd_v[k] -= (1.0 / 2.0 * (float)(x_minus_mu * x_minus_mu) / (float)(variance));
			}
			if (max < pd_v[k]) max = pd_v[k];
		}
		for (int k = 0; k < 10; k++) result_flag += exp(pd_v[k] - max);
		b[j + 1] = max + log(result_flag);
	}
}

void find_word_address (){
    for (int i = 0; i < input_vector_num; i++) {
		if (result_seq[i] == ph_end_index[0] && result_seq[i - 1] != ph_end_index[0]) {
			word_address[word_index] = 0;
			word_index++;
		}
		if (result_seq[i] == ph_end_index[1] && result_seq[i - 1] != ph_end_index[1]) {
			word_address[word_index] = 1;
			word_index++;
		}
		if (result_seq[i] == ph_end_index[2] && result_seq[i - 1] != ph_end_index[2]) {
			word_address[word_index] = 2;
			word_index++;
		}
		if (result_seq[i] == ph_end_index[3] && result_seq[i - 1] != ph_end_index[3]) {
			word_address[word_index] = 3;
			word_index++;
		}
		if (result_seq[i] == ph_end_index[4] && result_seq[i - 1] != ph_end_index[4]) {
			word_address[word_index] = 4;
			word_index++;
		}
		if (result_seq[i] == ph_end_index[5] && result_seq[i - 1] != ph_end_index[5]) {
			word_address[word_index] = 5;
			word_index++;
		}
		if (result_seq[i] == ph_end_index[6] && result_seq[i - 1] != ph_end_index[6]) {
			word_address[word_index] = 6;
			word_index++;
		}
		if (result_seq[i] == ph_end_index[7] && result_seq[i - 1] != ph_end_index[7]) {
			word_address[word_index] = 7;
			word_index++;
		}
		if (result_seq[i] == ph_end_index[8] && result_seq[i - 1] != ph_end_index[8]) {
			word_address[word_index] = 8;
			word_index++;
		}
		if (result_seq[i] == ph_end_index[9] && result_seq[i - 1] != ph_end_index[9]) {
			word_address[word_index] = 9;
			word_index++;
		}
		if (result_seq[i] == ph_end_index[10] && result_seq[i - 1] != ph_end_index[10]) {
			word_address[word_index] = 10;
			word_index++;
		}
		if (result_seq[i] == ph_end_index[11] && result_seq[i - 1] == ph_end_index[11]) {
			word_address[word_index] = 11;
			word_index++;
		}
	}
}

int main(){ 
  FILE *refer, *dir, *record;
  record = fopen("recognized", "w");
  parse_unigram();
  parse_bigram();
  get_trans_mat();
	refer = fopen("reference.txt", "r");
	fprintf(record, "#!MLF!#\n");
	char input_string[30];
	char rec_string[30];
	char dir_string[30];
  int flag = 0;
	while (fscanf(refer, "%s", &input_string) != EOF) {
		if (input_string[0] == '"'){
			memset(&input_vec, 0, sizeof(input_vec));
			memset(&sequence, -1, sizeof(sequence));
			memset(&result_seq, 0, sizeof(result_seq));
			memset(&word_address, -1, sizeof(word_address));
			//초기화를 해주자
			flag = strlen(input_string);
			for (int i = 0; i < flag; i++) rec_string[i] = input_string[i];
      rec_string[flag - 2] = 'c';
      rec_string[flag - 3] = 'e';
			rec_string[flag - 4] = 'r';
			fprintf(record, "%s\n", rec_string);
            //무슨 데이턴지 기록
			for (int i = 0; i < flag; i++) dir_string[i] = input_string[i];
			flag = 1;
			while (dir_string[flag] != '"') {
				dir_string[flag - 1] = dir_string[flag];
				flag++;
			}
			dir_string[flag] = '\0';
			dir_string[flag - 1] = '\0';
			dir_string[flag - 2] = 't';
			dir_string[flag - 3] = 'x'; 
			dir_string[flag - 4] = 't';
			dir = fopen(dir_string, "r");
			fscanf(dir, "%d %d", &input_vector_num, &input_vector_dim);
			for (int i = 0; i < input_vector_num; i++)
				for (int j = 0; j < input_vector_dim; j++)
					fscanf(dir, "%e", &input_vec[i][j]); //dir에서 데이터 가져오기
     /*********************비터비이이이***********************/
			for (int i = 0; i < input_vector_num; i++){
            calculate_prob(i);
				if (i == 0) {
					for (int j = 0; j < TRANS_DIMENSION; j++) probability[i][j] = t[0][j] + b[j];
				}
				else {
                    for (int j = 0; j < TRANS_DIMENSION; j++) {
						float max = INF;
						int tmp_seq = INIT_FLAG;
						for (int k = 0; k < TRANS_DIMENSION; k++) {
							if (max < probability[i - 1][k] + t[k][j] + b[j]) {
								max = probability[i - 1][k] + t[k][j] + b[j];
								tmp_seq = k;
							}
						}
						probability[i][j] = max;
						sequence[i][j] = tmp_seq;
					}
				}
			}
			float max_prob = INF;
			int highest_seq = INIT_FLAG; 
			for (int i = 0; i < TRANS_DIMENSION; i++) {
				if (max_prob < probability[input_vector_num - 1][i]) {
					max_prob = probability[input_vector_num - 1][i];
					highest_seq = i;
				}
			}
			result_seq[input_vector_num - 1] = highest_seq;
			for (int i = input_vector_num - 1; i > 0; i--) result_seq[i - 1] = sequence[i][result_seq[i]];
            word_index = 0;
			find_word_address();
			for (int i = 1; i < 10; i++) 
				if (word_address[i] != INIT_FLAG) fprintf(record, "%s\n", words[word_address[i]]);
			fprintf(record, ".\n");
			fclose(dir);
			if (count%10 == 0) printf("%.2f퍼센트 완료\n", ((float)count/1242)*100);
			count++;
		}
	}
	printf("완료되었습니다\n");
	fclose(record);
	fclose(refer);
	return 0;
}