


#include "gtest/gtest.h"
#include "Arduino.h"
#include "Timer.h"



static const uint32_t MAX_TIME = (uint32_t)-1;


TEST(TimerTest, testFromTheBeginning) {

  Timer timer(500);
  ASSERT_FALSE(timer.isReady());
  timer.start();
  ASSERT_FALSE(timer.isReady());
  testSetMillis(499);
  ASSERT_FALSE(timer.isReady());
  testSetMillis(501);
  ASSERT_TRUE(timer.isReady());

}


TEST(TimerTest, testInTheMiddle) {

  testSetMillis(10000);

  Timer timer(500);
  ASSERT_FALSE(timer.isReady());
  timer.start();
  ASSERT_FALSE(timer.isReady());
  testSetMillis(10499);
  ASSERT_FALSE(timer.isReady());
  testSetMillis(10501);
  ASSERT_TRUE(timer.isReady());

}





TEST(TimerTest, testOveflow) {
  testSetMillis(MAX_TIME - 199);
  Timer timer(500);
  ASSERT_FALSE(timer.isReady());
  timer.start();
  ASSERT_FALSE(timer.isReady());
  testSetMillis(MAX_TIME);
  ASSERT_FALSE(timer.isReady());
  testSetMillis(1);
  ASSERT_FALSE(timer.isReady());
  testSetMillis(299);
  ASSERT_FALSE(timer.isReady());
  testSetMillis(301);
  ASSERT_TRUE(timer.isReady());

}





TEST(TimerTest, testOveflow2) {
  testSetMillis(10);
  Timer timer(500);
  timer.start();
  testSetMillis(MAX_TIME);
  ASSERT_TRUE(timer.isReady());
}


