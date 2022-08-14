#ifndef UserDto_hpp
#define UserDto_hpp

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

ENUM(Role, v_int32,
     VALUE(GUEST, 0, "ROLE_GUEST"),
     VALUE(ADMIN, 1, "ROLE_ADMIN"))

class UserDto : public oatpp::DTO {
  DTO_INIT(UserDto, DTO)

  DTO_FIELD(Int32, id);
  DTO_FIELD(String, userName, "username");
  DTO_FIELD(String, email, "email");
  DTO_FIELD(String, password, "password");
  DTO_FIELD(Enum<Role>::AsString, role, "role");
};

class ParameterSetDto : public oatpp::DTO {
  DTO_INIT(ParameterSetDto, DTO)

  // DTO_FIELD(Float32, b_e_a, "B_E_a");
  DTO_FIELD(Float32, b_e_a, "B_E_a");
  DTO_FIELD(Float32, b_i_0, "B_I_0");
  DTO_FIELD(Float32, b_k_v, "B_K_V");
  DTO_FIELD(Float32, b_p___m, "B_P___M");
  DTO_FIELD(Float32, b_r_a, "B_R_A");
  DTO_FIELD(Float32, c_d, "C_D");
  DTO_FIELD(Float32, c_l, "C_L");
  DTO_FIELD(Float32, c_dcs, "C_dcs");
  DTO_FIELD(Float32, c_l_max, "C_L_max");
  DTO_FIELD(Float32, e_b, "E_B");
  DTO_FIELD(Float32, g, "g");
  DTO_FIELD(Float32, k_v, "K_V");
  DTO_FIELD(Float32, i_in, "I_in");
  DTO_FIELD(Float32, i_0, "I_0");
  DTO_FIELD(Float32, m_b, "m_B");
  DTO_FIELD(Float32, m_m, "m_M");
  DTO_FIELD(Float32, m_tip, "M_tip");
  DTO_FIELD(Float32, m_total, "m_total");
  DTO_FIELD(Float32, m_0, "m_0");
  DTO_FIELD(Float32, p_in, "P_in");
  DTO_FIELD(Float32, p_out, "P_out");
  DTO_FIELD(Float32, p_out___max, "p_out___max");
  DTO_FIELD(Float32, r_p, "R_p");
  DTO_FIELD(Float32, r_a, "R_a");
  DTO_FIELD(Float32, r, "r");
  DTO_FIELD(Float32, s_w, "S_w");
  DTO_FIELD(Float32, t, "T");
  DTO_FIELD(Float32, tcs, "tcs");
  DTO_FIELD(Float32, v_f, "V_F");
  DTO_FIELD(Float32, v_in, "V_in");
  DTO_FIELD(Float32, v_l, "V_l");
  DTO_FIELD(Float32, v_st, "V_st");
  DTO_FIELD(Float32, w_a, "W_a");
  DTO_FIELD(Float32, n_d, "n_D");
  DTO_FIELD(Float32, n_p, "n_P");
  DTO_FIELD(Float32, n_p___ideal, "n_P___ideal");
  DTO_FIELD(Float32, n_s, "n_S");
  DTO_FIELD(Float32, p_a, "p_a");
  DTO_FIELD(Float32, q, "Q");
  DTO_FIELD(Float32, z, "Z");
  DTO_FIELD(Float32, c, "C");
};

#include OATPP_CODEGEN_END(DTO)

#endif /* UserDto_hpp */
