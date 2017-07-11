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

#include <gtest/gtest.h>
#include "ignition/fuel-tools/ClientConfig.hh"

namespace ignft = ignition::fuel_tools;
using namespace ignition;
using namespace ignft;


/////////////////////////////////////////////////
/// \brief Initially no servers in config
TEST(ClientConfig, InitiallyNoServers)
{
  ClientConfig config;
  EXPECT_EQ(0u, config.Servers().size());
}

/////////////////////////////////////////////////
/// \brief Servers can be added
TEST(ClientConfig, ServersCanBeAdded)
{
  ClientConfig config;
  const std::string srvURL("asdf");
  config.AddServer(srvURL);

  ASSERT_EQ(1u, config.Servers().size());
  EXPECT_EQ(srvURL, config.Servers().front());
}

//////////////////////////////////////////////////
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
