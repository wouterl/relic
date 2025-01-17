/*
 * RELIC is an Efficient LIbrary for Cryptography
 * Copyright (C) 2007-2019 RELIC Authors
 *
 * This file is part of RELIC. RELIC is legal property of its developers,
 * whose names are not listed here. Please refer to the COPYRIGHT file
 * for contact information.
 *
 * RELIC is free software; you can redistribute it and/or modify it under the
 * terms of the version 2.1 (or later) of the GNU Lesser General Public License
 * as published by the Free Software Foundation; or version 2.0 of the Apache
 * License as published by the Apache Software Foundation. See the LICENSE files
 * for more details.
 *
 * RELIC is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the LICENSE files for more details.
 *
 * You should have received a copy of the GNU Lesser General Public or the
 * Apache License along with RELIC. If not, see <https://www.gnu.org/licenses/>
 * or <https://www.apache.org/licenses/>.
 */

/**
 * @file
 *
 * Implementation of exponentiation in extensions defined over prime fields.
 *
 * @ingroup fpx
 */

#include "relic_core.h"

/*============================================================================*/
/* Public definitions                                                         */
/*============================================================================*/

void fp2_exp(fp2_t c, fp2_t a, bn_t b) {
	fp2_t t;

	if (bn_is_zero(b)) {
		fp2_set_dig(c, 1);
		return;
	}

	fp2_null(t);

	TRY {
		fp2_new(t);

		fp2_copy(t, a);
		for (int i = bn_bits(b) - 2; i >= 0; i--) {
			fp2_sqr(t, t);
			if (bn_get_bit(b, i)) {
				fp2_mul(t, t, a);
			}
		}

		if (bn_sign(b) == RLC_NEG) {
			fp2_inv(c, t);
		} else {
			fp2_copy(c, t);
		}
	}
	CATCH_ANY {
		THROW(ERR_CAUGHT);
	}
	FINALLY {
		fp2_free(t);
	}
}

void fp2_exp_dig(fp2_t c, fp2_t a, dig_t b) {
	fp2_t t;

	if (b == 0) {
		fp2_set_dig(c, 1);
		return;
	}

	fp2_null(t);

	TRY {
		fp2_new(t);

		fp2_copy(t, a);
		for (int i = util_bits_dig(b) - 2; i >= 0; i--) {
			fp2_sqr(t, t);
			if (b & ((dig_t)1 << i)) {
				fp2_mul(t, t, a);
			}
		}

		fp2_copy(c, t);
	}
	CATCH_ANY {
		THROW(ERR_CAUGHT);
	}
	FINALLY {
		fp2_free(t);
	}
}

void fp3_exp(fp3_t c, fp3_t a, bn_t b) {
	fp3_t t;

	if (bn_is_zero(b)) {
		fp3_set_dig(c, 1);
		return;
	}

	fp3_null(t);

	TRY {
		fp3_new(t);

		fp3_copy(t, a);

		for (int i = bn_bits(b) - 2; i >= 0; i--) {
			fp3_sqr(t, t);
			if (bn_get_bit(b, i)) {
				fp3_mul(t, t, a);
			}
		}

		if (bn_sign(b) == RLC_NEG) {
			fp3_inv(c, t);
		} else {
			fp3_copy(c, t);
		}
	}
	CATCH_ANY {
		THROW(ERR_CAUGHT);
	}
	FINALLY {
		fp3_free(t);
	}
}

void fp4_exp(fp4_t c, fp4_t a, bn_t b) {
	fp4_t t;

	if (bn_is_zero(b)) {
		fp4_set_dig(c, 1);
		return;
	}

	fp4_null(t);

	TRY {
		fp4_new(t);

		fp4_copy(t, a);

		for (int i = bn_bits(b) - 2; i >= 0; i--) {
			fp4_sqr(t, t);
			if (bn_get_bit(b, i)) {
				fp4_mul(t, t, a);
			}
		}

		if (bn_sign(b) == RLC_NEG) {
			fp4_inv(c, t);
		} else {
			fp4_copy(c, t);
		}
	}
	CATCH_ANY {
		THROW(ERR_CAUGHT);
	}
	FINALLY {
		fp4_free(t);
	}
}

void fp6_exp(fp6_t c, fp6_t a, bn_t b) {
	fp6_t t;

	if (bn_is_zero(b)) {
		fp6_set_dig(c, 1);
		return;
	}

	fp6_null(t);

	TRY {
		fp6_new(t);

		fp6_copy(t, a);

		for (int i = bn_bits(b) - 2; i >= 0; i--) {
			fp6_sqr(t, t);
			if (bn_get_bit(b, i)) {
				fp6_mul(t, t, a);
			}
		}

		if (bn_sign(b) == RLC_NEG) {
			fp6_inv(c, t);
		} else {
			fp6_copy(c, t);
		}
	}
	CATCH_ANY {
		THROW(ERR_CAUGHT);
	}
	FINALLY {
		fp6_free(t);
	}
}

void fp8_exp(fp8_t c, fp8_t a, bn_t b) {
	fp8_t t;

	if (bn_is_zero(b)) {
		fp8_set_dig(c, 1);
		return;
	}

	fp8_null(t);

	TRY {
		fp8_new(t);

		fp8_copy(t, a);

		for (int i = bn_bits(b) - 2; i >= 0; i--) {
			fp8_sqr(t, t);
			if (bn_get_bit(b, i)) {
				fp8_mul(t, t, a);
			}
		}

		if (bn_sign(b) == RLC_NEG) {
			fp8_inv(c, t);
		} else {
			fp8_copy(c, t);
		}
	}
	CATCH_ANY {
		THROW(ERR_CAUGHT);
	}
	FINALLY {
		fp8_free(t);
	}
}

void fp9_exp(fp9_t c, fp9_t a, bn_t b) {
	fp9_t t;

	if (bn_is_zero(b)) {
		fp9_set_dig(c, 1);
		return;
	}

	fp9_null(t);

	TRY {
		fp9_new(t);

		fp9_copy(t, a);

		for (int i = bn_bits(b) - 2; i >= 0; i--) {
			fp9_sqr(t, t);
			if (bn_get_bit(b, i)) {
				fp9_mul(t, t, a);
			}
		}

		if (bn_sign(b) == RLC_NEG) {
			fp9_inv(c, t);
		} else {
			fp9_copy(c, t);
		}
	}
	CATCH_ANY {
		THROW(ERR_CAUGHT);
	}
	FINALLY {
		fp9_free(t);
	}
}

void fp12_exp(fp12_t c, fp12_t a, bn_t b) {
	fp12_t t;

	if (bn_is_zero(b)) {
		fp12_set_dig(c, 1);
		return;
	}

	fp12_null(t);

	TRY {
		fp12_new(t);

		if (fp12_test_cyc(a)) {
			fp12_exp_cyc(c, a, b);
		} else {
			fp12_copy(t, a);

			for (int i = bn_bits(b) - 2; i >= 0; i--) {
				fp12_sqr(t, t);
				if (bn_get_bit(b, i)) {
					fp12_mul(t, t, a);
				}
			}

			if (bn_sign(b) == RLC_NEG) {
				fp12_inv(c, t);
			} else {
				fp12_copy(c, t);
			}
		}
	}
	CATCH_ANY {
		THROW(ERR_CAUGHT);
	}
	FINALLY {
		fp12_free(t);
	}
}

void fp12_exp_dig(fp12_t c, fp12_t a, dig_t b) {
	fp12_t t;

	if (b == 0) {
		fp12_set_dig(c, 1);
		return;
	}

	fp12_null(t);

	TRY {
		fp12_new(t);

		fp12_copy(t, a);

		if (fp12_test_cyc(a)) {
			for (int i = util_bits_dig(b) - 2; i >= 0; i--) {
				fp12_sqr_cyc(t, t);
				if (b & ((dig_t)1 << i)) {
					fp12_mul(t, t, a);
				}
			}
		} else {
			for (int i = util_bits_dig(b) - 2; i >= 0; i--) {
				fp12_sqr(t, t);
				if (b & ((dig_t)1 << i)) {
					fp12_mul(t, t, a);
				}
			}
		}

		fp12_copy(c, t);
	}
	CATCH_ANY {
		THROW(ERR_CAUGHT);
	}
	FINALLY {
		fp12_free(t);
	}
}

void fp18_exp(fp18_t c, fp18_t a, bn_t b) {
	fp18_t t;

	if (bn_is_zero(b)) {
		fp18_set_dig(c, 1);
		return;
	}

	fp18_null(t);

	TRY {
		fp18_new(t);

		fp18_copy(t, a);

		for (int i = bn_bits(b) - 2; i >= 0; i--) {
			fp18_sqr(t, t);
			if (bn_get_bit(b, i)) {
				fp18_mul(t, t, a);
			}
		}

		if (bn_sign(b) == RLC_NEG) {
			fp18_inv(c, t);
		} else {
			fp18_copy(c, t);
		}
	}
	CATCH_ANY {
		THROW(ERR_CAUGHT);
	}
	FINALLY {
		fp18_free(t);
	}
}

void fp24_exp(fp24_t c, fp24_t a, bn_t b) {
	fp24_t t;

	if (bn_is_zero(b)) {
		fp24_set_dig(c, 1);
		return;
	}

	fp24_null(t);

	TRY {
		fp24_new(t);

		fp24_copy(t, a);

		for (int i = bn_bits(b) - 2; i >= 0; i--) {
			fp24_sqr(t, t);
			if (bn_get_bit(b, i)) {
				fp24_mul(t, t, a);
			}
		}

		if (bn_sign(b) == RLC_NEG) {
			fp24_inv(c, t);
		} else {
			fp24_copy(c, t);
		}
	}
	CATCH_ANY {
		THROW(ERR_CAUGHT);
	}
	FINALLY {
		fp24_free(t);
	}
}

void fp48_exp(fp48_t c, fp48_t a, bn_t b) {
	fp48_t t;

	if (bn_is_zero(b)) {
		fp48_set_dig(c, 1);
		return;
	}

	fp48_null(t);

	TRY {
		fp48_new(t);

		if (fp48_test_cyc(a)) {
			fp48_exp_cyc(c, a, b);
		} else {
			fp48_copy(t, a);

			for (int i = bn_bits(b) - 2; i >= 0; i--) {
				fp48_sqr(t, t);
				if (bn_get_bit(b, i)) {
					fp48_mul(t, t, a);
				}
			}

			if (bn_sign(b) == RLC_NEG) {
				fp48_inv(c, t);
			} else {
				fp48_copy(c, t);
			}
		}
	}
	CATCH_ANY {
		THROW(ERR_CAUGHT);
	}
	FINALLY {
		fp48_free(t);
	}
}

void fp48_exp_dig(fp48_t c, fp48_t a, dig_t b) {
	fp48_t t;

	if (b == 0) {
		fp48_set_dig(c, 1);
		return;
	}

	fp48_null(t);

	TRY {
		fp48_new(t);

		fp48_copy(t, a);

		if (fp48_test_cyc(a)) {
			for (int i = util_bits_dig(b) - 2; i >= 0; i--) {
				fp48_sqr_cyc(t, t);
				if (b & ((dig_t)1 << i)) {
					fp48_mul(t, t, a);
				}
			}
		} else {
			for (int i = util_bits_dig(b) - 2; i >= 0; i--) {
				fp48_sqr(t, t);
				if (b & ((dig_t)1 << i)) {
					fp48_mul(t, t, a);
				}
			}
		}

		fp48_copy(c, t);
	}
	CATCH_ANY {
		THROW(ERR_CAUGHT);
	}
	FINALLY {
		fp48_free(t);
	}
}

void fp54_exp(fp54_t c, fp54_t a, bn_t b) {
	fp54_t t;

	if (bn_is_zero(b)) {
		fp54_set_dig(c, 1);
		return;
	}

	fp54_null(t);

	TRY {
		fp54_new(t);

		fp54_copy(t, a);

		for (int i = bn_bits(b) - 2; i >= 0; i--) {
			fp54_sqr(t, t);
			if (bn_get_bit(b, i)) {
				fp54_mul(t, t, a);
			}
		}

		if (bn_sign(b) == RLC_NEG) {
			fp54_inv(c, t);
		} else {
			fp54_copy(c, t);
		}
	}
	CATCH_ANY {
		THROW(ERR_CAUGHT);
	}
	FINALLY {
		fp54_free(t);
	}
}

void fp54_exp_dig(fp54_t c, fp54_t a, dig_t b) {
	fp54_t t;

	if (b == 0) {
		fp54_set_dig(c, 1);
		return;
	}

	fp54_null(t);

	TRY {
		fp54_new(t);

		fp54_copy(t, a);

		if (fp54_test_cyc(a)) {
			for (int i = util_bits_dig(b) - 2; i >= 0; i--) {
				fp54_sqr_cyc(t, t);
				if (b & ((dig_t)1 << i)) {
					fp54_mul(t, t, a);
				}
			}
		} else {
			for (int i = util_bits_dig(b) - 2; i >= 0; i--) {
				fp54_sqr(t, t);
				if (b & ((dig_t)1 << i)) {
					fp54_mul(t, t, a);
				}
			}
		}

		fp54_copy(c, t);
	}
	CATCH_ANY {
		THROW(ERR_CAUGHT);
	}
	FINALLY {
		fp54_free(t);
	}
}
