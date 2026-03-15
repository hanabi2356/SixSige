# 작업 일지
<26/02/14>
  - 맵 완성

<26/03/07>
  - 플레이어 이동 애니메이션 적용 및 메인 총기 플레이어의 부착 완료

<26/03/08>
  - 8방향 이동 애니메이션 적용
  - Lean 애니메이션 시퀀스 완성(컨트롤 릭을 이용해 제작)
  - Q,E를 누르면 Lean 애니메이션 재생 완성

<26/03/09>
  - Lean 애니메이션에 보간 적용
  - Lean Blend Space 1D에 적용안한 IDLE 적용
  - Sprint 키 입력 추가

<26/03/10>
  - Sprint 기능 구현
    
<26/03/14>
  - Crunch 애니메이션 적용
  - Prone 구현 완료(애니메이션이 없음 이슈)
  - Stance에 따른 Max Walk Speed 변경하는 기능 완료
  - Crosshair 제작 완료
  - 가시성을 위한 몇몇 로직 함수화

<26/03/15>
  - 플레이어 Stance 별 CapsuleComponentHalfSize 적용
  - 
  
# 원작 게임(Rainbow Six Sige)기능 노트
  - Sprint W + Shift를 같이 눌렀을 때만 작동
  - c 입력 시 Crunch / crtl 입력 시 Prone
  - v 입력 시 근접 공격
  - f 입력 시 벽 강화 및 바리케이드 설치 
  - z 입력 시 LineTrace를 기준으로 핑을 찍어준다
    
# 당장 할 일
~~- 크로스헤어 시스템 제작~~
~~- sprint 애니메이션 적용~~
~~- Crunch / Prone 모션 적용~~
~~- Stance에 따른 CapsuleComponent Height 조절~~
  
  - 조준 시스템 적용
    
# 나중에 할 일
~~-IDLE 모션의 총기가 과하게 높게 설정되어있음(새롭게 구할 예정)~~

  - 방향 전환시 애니메이션 튀는 현상 수정
  - Prone 애니메이션 구하기(Maximo에 없음)
    

# 버그 리포트
<해결된 버그>
  - W 이외에 버튼과 shift를 눌러도 sprint가 되는 현상
  - Stance 변경 시 CapsuleComponent의 CapsuleHalfSize도 변경하는데 변경 시 캐릭테 외형이 눌리는 현상 발생
    - 해결 방법 : CapsuleHalfSize를 바꿀때 Mesh의 Relative Location을 -CapsuleHalfSize 만큼 바꿔 위치를 동기화 한다

<해결되지 않은 버그>
  - Crunch/Prone 자세에서 Sprint가 되는 현상(Sprint시 Stand 상태로 변환)

# 오브젝트 및 함수 기능
  - MovementVelocity : 현재 Stance별로 Max Walk Speed를 조절한다
  - IsCrunch?/IsProne?/IsCrunch?(순수 함수) : 현재 상태를 받아서 true/false를 반환한다
  - UpdateCrosshair : 플레이어의 Velocity를 기반으로 Crosshair가 벌어지는 거리를 계산한다
  - UpdateLeaning : 플레이어의 특정 Lean 각도 까지 FInterp To를 이용해 보간하여 각도를 업데이트 한다(Tick의 DeltaTime 기반으로 계산)
  
