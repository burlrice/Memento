namespace UnitTests
{
    using Pertinax;
    using Xunit;
    using Xunit.Abstractions;

    public class SimpleTypeTests
    {
        private readonly ITestOutputHelper output;

        public SimpleTypeTests(ITestOutputHelper output)
        {
            this.output = output;
        }

        [Fact] public void SByte() => Test(sbyte.MinValue, sbyte.MaxValue, sbyte.MaxValue / 2);
        [Fact] public void Byte() => Test(byte.MinValue, byte.MaxValue, byte.MaxValue / 2);
        [Fact] public void Int16() => Test(short.MinValue, short.MaxValue, short.MaxValue / 2);
        [Fact] public void UInt16() => Test(ushort.MinValue, ushort.MaxValue, ushort.MaxValue / 2);
        [Fact] public void Int32() => Test(int.MinValue, int.MaxValue, int.MaxValue / 2);
        [Fact] public void UInt32() => Test(uint.MinValue, uint.MaxValue, uint.MaxValue / 2);
        [Fact] public void Int64() => Test(long.MinValue, long.MaxValue, long.MaxValue / 2);
        [Fact] public void UInt64() => Test(ulong.MinValue, ulong.MaxValue, ulong.MaxValue / 2);
        [Fact] public void Char() => Test(char.MinValue, char.MaxValue, char.MaxValue / 2);
        [Fact] public void Single() => Test(float.MinValue, float.MaxValue, float.MaxValue / 2);
        [Fact] public void Double() => Test(double.MinValue, double.MaxValue, double.MaxValue / 2);
        [Fact] public void Boolean() => Test(false, true, false);
        [Fact] public void Decimal() => Test(decimal.MinValue, decimal.MaxValue, decimal.MaxValue / 2);

        private void Test<T>(T oldValue, T newValue, T intermediateValue)
        {
            var expected = oldValue;

            output.WriteLine($"Testing {oldValue.GetType().Name}, oldValue: {oldValue}, newValue: {newValue}...");

            {
                using var memento = new Memento<T>(ref oldValue);
                T test = intermediateValue;

                memento.Set(newValue);

                output.WriteLine($"oldValue: {oldValue}, newValue: {newValue}");

                Assert.Equal(oldValue, newValue);

                memento.Get(ref test);

                output.WriteLine($"oldValue: {oldValue}, test: {test}");
                Assert.Equal(oldValue, test);
            }

            output.WriteLine($"oldValue: {oldValue}, expected: {expected}");

            Assert.Equal(oldValue, expected);
        }
    }
}