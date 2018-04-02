/*
 * Copyright (C) 2017 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include "ignition/fuel_tools/Result.hh"

namespace ignft = ignition::fuel_tools;
using namespace ignition;
using namespace ignft;


class ignft::ResultPrivate
{
  /// \brief a type of result
  public: ResultType type = ResultType::UNKNOWN;
};


//////////////////////////////////////////////////
Result::~Result()
{
}

//////////////////////////////////////////////////
ResultType Result::Type() const
{
  return this->dataPtr->type;
}

//////////////////////////////////////////////////
Result::Result(const ResultType _type) : dataPtr(new ResultPrivate)
{
  this->dataPtr->type = _type;
}

//////////////////////////////////////////////////
Result::Result(const int _type)
: dataPtr(new ResultPrivate)
{
  switch (_type)
  {
    default:
    case UNKNOWN:
      this->dataPtr->type = ResultType::UNKNOWN;
      break;
    case DELETE:
      this->dataPtr->type = ResultType::DELETE;
      break;
    case DELETE_NOT_FOUND:
      this->dataPtr->type = ResultType::DELETE_NOT_FOUND;
      break;
    case DELETE_ERROR:
      this->dataPtr->type = ResultType::DELETE_ERROR;
      break;
    case FETCH:
      this->dataPtr->type = ResultType::FETCH;
      break;
    case FETCH_ALREADY_EXISTS:
      this->dataPtr->type = ResultType::FETCH_ALREADY_EXISTS;
      break;
    case FETCH_NOT_FOUND:
      this->dataPtr->type = ResultType::FETCH_NOT_FOUND;
      break;
    case FETCH_ERROR:
      this->dataPtr->type = ResultType::FETCH_ERROR;
      break;
    case UPLOAD:
      this->dataPtr->type = ResultType::UPLOAD;
      break;
    case UPLOAD_ALREADY_EXISTS:
      this->dataPtr->type = ResultType::UPLOAD_ALREADY_EXISTS;
      break;
    case UPLOAD_ERROR:
      this->dataPtr->type = ResultType::UPLOAD_ERROR;
      break;
  }
}

//////////////////////////////////////////////////
Result::Result(const Result &_orig) : dataPtr(new ResultPrivate)
{
  *(this->dataPtr) = *(_orig.dataPtr);
}

//////////////////////////////////////////////////
Result::operator bool() const
{
  switch (this->dataPtr->type)
  {
    case ResultType::DELETE:
    case ResultType::FETCH:
    case ResultType::FETCH_ALREADY_EXISTS:
    case ResultType::UPLOAD:
      return true;
    default:
      return false;
  }
}

//////////////////////////////////////////////////
std::string Result::ReadableResult() const
{
  switch (this->dataPtr->type)
  {
    case ResultType::DELETE:
      return "Successfully deleted";
    case ResultType::FETCH:
      return "Successfully fetched from server";
    case ResultType::FETCH_ALREADY_EXISTS:
      return "Already in cache, did not fetch from server";
    case ResultType::UPLOAD:
      return "Successfully uploaded to server";
    case ResultType::DELETE_NOT_FOUND:
      return "Could not delete, model not found";
    case ResultType::DELETE_ERROR:
      return "Delete failed. Other errors";
    case ResultType::FETCH_NOT_FOUND:
        return "Model not found";
    case ResultType::FETCH_ERROR:
        return "Fetch failed. Other errors";
    case ResultType::UPLOAD_ALREADY_EXISTS:
        return "Model already exists";
    case ResultType::UPLOAD_ERROR:
        return "Upload failed. Other errors";
    case ResultType::UNKNOWN:
    default:
      return "Unknown result";
  }
}
