cmake_minimum_required( VERSION 3.14 )
project( EffectiveCpp )

set( CMAKE_CXX_STANDARD 17 )

add_executable( EffectiveCpp main.cpp NamedObject.cpp NamedObject.h HomeForSale.cpp HomeForSale.h Uncopyable.cpp Uncopyable.h UncopyableHomeForSale.cpp UncopyableHomeForSale.h AWOV.cpp AWOV.h DerivedAWOV.cpp DerivedAWOV.h DerivedNamedObject.cpp DerivedNamedObject.h Lock.cpp Lock.h Lock2.cpp Lock2.h chapter18_Investment.cpp chapter18_Investment.h chapter19_HowToDesignClass.cpp chapter19_HowToDesignClass.h chapter20_ConstRefParamIsBetter.cpp chapter20_ConstRefParamIsBetter.h chapter21_DoNotReturnRef.cpp chapter21_DoNotReturnRef.h chapter22_PrivateDataMember.cpp chapter22_PrivateDataMember.h chapter23_NoMemberMethodIsBetter.cpp chapter23_NoMemberMethodIsBetter.h chapter24_NoMemberMethodForTypeConversion.cpp chapter24_NoMemberMethodForTypeConversion.h )
