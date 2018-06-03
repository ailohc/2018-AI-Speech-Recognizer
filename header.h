#include "hmm.h"
#include "words.h"

#define INF -100000000
#define TRANS_DIMENSION 127
#define DATA_MAX 700
#define INIT_FLAG -1

int count;

float unigram[12];
float bigram[12][12];

float t[TRANS_DIMENSION][TRANS_DIMENSION];

int input_vector_num;
int input_vector_dim;
float input_vec[DATA_MAX][N_DIMENSION];
int sequence[DATA_MAX][TRANS_DIMENSION];

float pd_v[10];
float probability[DATA_MAX][TRANS_DIMENSION];
float b[TRANS_DIMENSION] = { INF, };

int result_seq[DATA_MAX];
int word_index;
int word_address[10];

void parse_unigram ();
void parse_bigram ();
void get_trans_mat();
void calculate_prob ();
void find_word_address ();