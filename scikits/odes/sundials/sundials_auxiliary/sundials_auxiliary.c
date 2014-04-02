#include <sundials/sundials_types.h>
#include <sundials/sundials_direct.h>
#include <sundials/sundials_nvector.h>
#include <nvector/nvector_serial.h>

/* N_Vector content access functions */
N_VectorContent_Serial nv_content_s(N_Vector v) {
    return (N_VectorContent_Serial)(v->content);
}

long int nv_length_s(N_VectorContent_Serial vc_s) {
    return vc_s->length;
}

booleantype nv_own_data_s(N_VectorContent_Serial vc_s) {
    return vc_s->own_data;
}

realtype* nv_data_s(N_VectorContent_Serial vc_s) {
    return vc_s->data;
}

typedef realtype *nv_content_data_s;

realtype get_nv_ith_s(nv_content_data_s vcd_s, int i) {
    return vcd_s[i];
}

void set_nv_ith_s(nv_content_data_s vcd_s, int i,
                          realtype new_value) {
    vcd_s[i] = new_value;
}

/* Dense matrix: acces functions */
typedef realtype *DlsMat_col;

int get_dense_N(DlsMat A) {
    return A->N;
}

int get_dense_M(DlsMat A) {
    return A->M;
}

int get_band_mu(DlsMat A) {
    return A->mu;
}

int get_band_ml(DlsMat A) {
    return A->ml;
}
realtype* get_dense_col(DlsMat A, int j) {
    return (A->cols)[j];
}

void set_dense_col(DlsMat A, int j, realtype *data) {
    (A->cols)[j] = data;
}

realtype get_dense_element(DlsMat A, int i, int j) {
    return (A->cols)[j][i];
}

void set_dense_element(DlsMat A, int i, int j, realtype aij) {
    (A->cols)[j][i] = aij;
}

/* Band matrix acces functions */
DlsMat_col get_band_col(DlsMat A, int j) {
    return ((A->cols)[j] + (A->s_mu));
}

void set_band_col(DlsMat A, int j, realtype *data) {
    ((A->cols)[j]) = data;
}

realtype get_band_col_elem(DlsMat_col col_j, int i, int j) {
    return col_j[(i)-(j)];
}

void set_band_col_elem(DlsMat_col col_j, int i, int j, realtype aij) {
    col_j[(i)-(j)] = aij;
}
realtype get_band_element(DlsMat A, int i, int j) {
    return ((A->cols)[j][(i)-(j)+(A->s_mu)]);
}

void set_band_element(DlsMat A, int i, int j, realtype aij) {
    (A->cols)[j][(i)-(j)+(A->s_mu)] = aij;
}
