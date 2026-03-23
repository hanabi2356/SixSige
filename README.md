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
  - 플레이어 Stance 별 CapsuleHalfHeight 적용
  - 조준 시스템 완성(half-aim)

<26/03/16>
  - 플레이어 무기 메시를 상속관계로 총기의 성능과 메시를 같이 관리하도록 변경
  - 조준시에는 Crosshair의 위치를 고정시키는 로직 UpdateCrosshair함수에 추가

<26/03/17>
  - 마우스 오른쪽 클릭 시 MuzzleEffect 및 FireSound 재생 로직 배치(미완성)

<26/03/19>
  - 사운드 및 이펙트 마우스 오른쪽 클릭 시에만 출력되도록 변경

<26/03/22>
  - LineTrace를 이용한 사격 기능 완성
  - 3번 입력 시 라이플을 Detach 하고 Throw 오브젝트를 Attach하는 기능 완성(미완성)

<26/03/23>
  - Throw 애니메이션 적용

# 원작 게임(Rainbow Six Sige)기능 노트
  - Sprint W + Shift를 같이 눌렀을 때만 작동
  - c 입력 시 Crunch / crtl 입력 시 Prone
  - v 입력 시 근접 공격
  - f 입력 시 벽 강화 및 바리케이드 설치 
  - z 입력 시 LineTrace를 기준으로 핑을 찍어준다
  - 마우스 우클릭 시 조준

    
# 당장 할 일  
  - 조준 애니메이션 적용
  
# 나중에 할 일
~~-IDLE 모션의 총기가 과하게 높게 설정되어있음(새롭게 구할 예정)~~

  - 방향 전환시 애니메이션 튀는 현상 수정
  - Prone 애니메이션 구하기(Maximo에 없음)
  - ADS 시스템 구현(만약 Lens 머테리얼이 있는 에셋이 있을 경우에는 PiP 기법으로 구현하고 없으면 레일에 아무것도 없는 에셋을 사용하여 아이언 사이트로 만들 예정)
  - MuzzleEffect 구하기

# 버그 리포트
<해결된 버그>
  - W 이외에 버튼과 shift를 눌러도 sprint가 되는 현상
  - Stance 변경 시 CapsuleComponent의 CapsuleHalfHeight도 변경하는데 변경 시 캐릭테 외형이 눌리는 현상 발생
    - 해결 방법 : CapsuleHalfHeignt를 바꿀때 Mesh의 Relative Location을 -CapsuleHalfHeight 만큼 바꿔 위치를 동기화 한다
  - Crunch/Prone 자세에서 Sprint가 되는 현상(Sprint시 Stand 상태로 변환)
  - 플레이시 FOV값이 0으로 강제 변환되는 현상(우클릭을 한 번 누르면 풀림)
  - WeaponFire 함수 실행 시 사운드 객체가 여러 개 생겨 사운드가 겹치는 문제 발생
  - 사격 시 마우스 클릭을 땐 후에 사운드가 재생되는 버그 발생(클릭 직 후에 사운드가 나와야함)
  - 3번 입력 시 Throwable 오브젝트가 누르는 동안 무한으로 생성되는 버그(Enhanced Input System에서 눌렸을 때를 Triggered가 아니라 started로 지정해야 한다)

<해결되지 않은 버그>
  - Crunch -> Stand 변화시 Lerp 미적용으로 인한 부자연스럽게 속도가 빠른 현상
  - 플레이만 눌러도 MuzzleEffect, FireSound가 무한 반복 재생됨(Tick 문제 같음)
  - 3번 입력 시 Throw오브젝트가 안보이는 현상(static mesh에 지정이 안됨)
  
    
# 오브젝트 및 함수 기능
  - MovementVelocity : 현재 Stance별로 Max Walk Speed를 조절한다
  - IsCrunch?/IsProne?/IsCrunch?(순수 함수) : 현재 상태를 받아서 true/false를 반환한다
  - UpdateCrosshair : 플레이어의 Velocity를 기반으로 Crosshair가 벌어지는 거리를 계산한다
  - UpdateLeaning : 플레이어의 특정 Lean 각도 까지 FInterp To를 이용해 보간하여 각도를 업데이트 한다(Tick의 DeltaTime 기반으로 계산)
  - UpdateCapsuleHeight : Stance별로 Mesh의 Z오프셋을 -CapsuleHalfHeight 만틈 주어 동기화 시킨 후 CapsuleHalfHeight를 TargetHalfHeight만큼 변경한다
  - UpdateFOV : 오른쪽 마우스 클릭에 따른 FOV값 변경
  - SpawnWeapon : 지정한 무기의 종류를 소환한다
  - InitWeapon : 상속받은 자식에서 총기의 성능과 스태틱 메시를 지정한다
  - WeaponFire(WeaponBase) : SoundWave를 재생시킨다
  - SwapWeapon : 현재 부착 되어있는 오브젝트를 삭제하고 새로운 오브젝트를 스폰하고 부착한다

# 기타 메모장
  - 연막탄
    - delay time : 1.5
    - duration time : 60
  - 수류탄
    - delay time : 5
  - 섬광탄
    - delay time : 2.3
  
