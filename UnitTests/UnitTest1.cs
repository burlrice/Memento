namespace UnitTests
{
    using Pertinax;

    using Xunit;

    public class UnitTest1
    {
        [Theory]
        [InlineData(1, 99)]
        public void Test1(int oldValue, int newValue)
        {
            var expected = oldValue;

            {
                using var memento = new Memento(ref oldValue);
                int test = 0;

                memento.Set(newValue);

                Assert.Equal(oldValue, newValue);

                memento.Get(ref test);

                Assert.Equal(oldValue, test);
            }

            Assert.Equal(oldValue, expected);
        }
    }
}