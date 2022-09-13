#include "UserService.hpp"
#include <exception>
#include <iostream>

oatpp::Object<ParameterSetDto> UserService::compute(const oatpp::Object<ParameterSetDto>& dto) {
  try {
    std::cout << "parameterset  [ ";
    std::cout << dto->b_e_a << " B_E_a ";
    std::cout << dto->b_i_0 << " B_I_0 ";
    std::cout << dto->b_k_v << " B_K_V ";
    std::cout << dto->b_p___m << " B_P___M ";
    std::cout << dto->b_r_a << " B_R_A ";
    std::cout << dto->c_d << " C_D ";
    std::cout << dto->c_l << " C_L ";
    std::cout << dto->c_dcs << " C_dcs ";
    std::cout << dto->c_l_max << " C_L_max ";
    std::cout << dto->e_b << " E_B ";
    std::cout << dto->g << " g ";
    std::cout << dto->k_v << " K_V ";
    std::cout << dto->i_in << " I_in ";
    std::cout << dto->i_0 << " I_0 ";
    std::cout << dto->m_b << " m_B ";
    std::cout << dto->m_m << " m_M ";
    std::cout << dto->m_tip << " M_tip ";
    std::cout << dto->m_total << " m_total ";
    std::cout << dto->m_0 << " m_0 ";
    std::cout << dto->p_in << " P_in ";
    std::cout << dto->p_out << " P_out ";
    std::cout << dto->p_out___max << " p_out___max ";
    std::cout << dto->r_p << " R_p ";
    std::cout << dto->r_a << " R_a ";
    std::cout << dto->r << " r ";
    std::cout << dto->s_w << " S_w ";
    std::cout << dto->t << " T ";
    std::cout << dto->tcs << " tcs ";
    std::cout << dto->v_f << " V_F ";
    std::cout << dto->v_in << " V_in ";
    std::cout << dto->v_l << " V_l ";
    std::cout << dto->v_st << " V_st ";
    std::cout << dto->w_a << " W_a ";
    std::cout << dto->n_d << " n_D ";
    std::cout << dto->n_p << " n_P ";
    std::cout << dto->n_p___ideal << " n_P___ideal ";
    std::cout << dto->n_s << " n_S ";
    std::cout << dto->p_a << " p_a ";
    std::cout << dto->q << " Q ";
    std::cout << dto->z << " Z ";
    std::cout << dto->c << " C"
              << " ] " << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return dto;
}

oatpp::Object<ParameterSet2Dto> UserService::compute2(const oatpp::Object<ParameterSet2Dto>& dto) {
  try {
    std::cout << "parameterset  [ ";
    std::cout << dto->b_s << " Battery charge state ";
    std::cout << dto->b_c << " Battery discharge state ";
    std::cout << dto->n_b << " No.Of Batteries ";
    std::cout << dto->e_c << " Energy capacity of ne cell";
    std::cout << dto->t_m << " Thrust per motor ";
    std::cout << dto->nm << " No.Of Motors";
    std::cout << dto->imax << " max Controller current";
    std::cout << dto->wm << " weight of motor ";
    std::cout << dto->wc << " weight of one controller ";
    std::cout << dto->wb << " weight of one battery ";
    std::cout << dto->wf<< " weight of frame";
    std::cout << dto->nc << " no.of controllers";
    std::cout << " ] " << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return dto;
}

oatpp::Object<UserDto> UserService::createUser(const oatpp::Object<UserDto>& dto) {
  auto dbResult = m_database->createUser(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto userId = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());

  return getUserById((v_int32)userId);
}

oatpp::Object<UserDto> UserService::updateUser(const oatpp::Object<UserDto>& dto) {
  auto dbResult = m_database->updateUser(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  return getUserById(dto->id);
}

oatpp::Object<UserDto> UserService::getUserById(const oatpp::Int32& id, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection) {
  auto dbResult = m_database->getUserById(id, connection);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "User not found");

  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<UserDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

  return result[0];
}

oatpp::Object<PageDto<oatpp::Object<UserDto>>> UserService::getAllUsers(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {
  oatpp::UInt32 countToFetch = limit;

  if (limit > 10) {
    countToFetch = 10;
  }

  auto dbResult = m_database->getAllUsers(offset, countToFetch);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<UserDto>>>();

  auto page = PageDto<oatpp::Object<UserDto>>::createShared();
  page->offset = offset;
  page->limit = countToFetch;
  page->count = items->size();
  page->items = items;

  return page;
}

oatpp::Object<StatusDto> UserService::deleteUserById(const oatpp::Int32& userId) {
  auto dbResult = m_database->deleteUserById(userId);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = "User was successfully deleted";
  return status;
}
