cmake_minimum_required( VERSION 3.14 )
project( EffectiveCpp )

set( CMAKE_CXX_STANDARD 17 )

add_executable( EffectiveCpp main.cpp NamedObject.cpp NamedObject.h HomeForSale.cpp HomeForSale.h Uncopyable.cpp Uncopyable.h UncopyableHomeForSale.cpp UncopyableHomeForSale.h AWOV.cpp AWOV.h DerivedAWOV.cpp DerivedAWOV.h DerivedNamedObject.cpp DerivedNamedObject.h Lock.cpp Lock.h Lock2.cpp Lock2.h Investment.cpp Investment.h )
