#pragma once

class chapter22_PrivateDataMember
{
    // note: 데이터 멤버는 왠만하면 private으로 하자
    // public 으로 하면 여러모로 불리함
    // private으로 해야 캡슐화, 사전조건, 사후조건, 동기화등의 구현 융통성을 누릴 수 있다.
    // 클래스의 불변속성 유지에 유리함
    // public으로 된 변수는 많은 곳에서 접근되니까 손을 대기 힘듬 => '캡슐화 되지 않은 변수' = '바꿀 수 없다' 라는 실질적 의미가 잇음
    // protected의 경우도 상속이 될 경우 많은곳에서 접근되므로 바꾸기 힘들다.
    
    // 평균값을 구하는 함수는 평균값을 저장해야할까 호출될때마다 구해야 할까?
    // 매우 적은 메모리(임베디드) 환경이면서 얼마 안걸릴경우에는 호출될때마다 구한다.
    // 메모리가 넉넉할 경우에는 구해놓은 값을 저장해놓는다.
    //

};
