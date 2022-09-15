
#ifndef CRUD_USERSERVICE_HPP
#define CRUD_USERSERVICE_HPP

#include "db/UserDb.hpp"
#include "dto/PageDto.hpp"
#include "dto/StatusDto.hpp"
#include "oatpp/core/macro/component.hpp"
#include "oatpp/web/protocol/http/Http.hpp"

class UserService {
 private:
  typedef oatpp::web::protocol::http::Status Status;

 private:
  OATPP_COMPONENT(std::shared_ptr<UserDb>, m_database);  // Inject database component
 public:
  oatpp::Object<ComputeResponseDto> compute(const oatpp::Object<ParameterSetDto>& dto);
  oatpp::Object<ParameterSet2Dto> compute2(const oatpp::Object<ParameterSet2Dto>& dto);
  oatpp::Object<UserDto> createUser(const oatpp::Object<UserDto>& dto);
  oatpp::Object<UserDto> updateUser(const oatpp::Object<UserDto>& dto);
  oatpp::Object<UserDto> getUserById(const oatpp::Int32& id, const oatpp::provider::ResourceHandle<oatpp::orm::Connection>& connection = nullptr);
  oatpp::Object<PageDto<oatpp::Object<UserDto>>> getAllUsers(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
  oatpp::Object<StatusDto> deleteUserById(const oatpp::Int32& id);
};

#endif  //CRUD_USERSERVICE_HPP
