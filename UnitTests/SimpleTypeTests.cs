namespace UnitTests
{
    using Pertinax;

    using Xunit;
    using Xunit.Abstractions;
    using static System.Net.Mime.MediaTypeNames;

    public class SimpleTypeTests
    {
        private readonly ITestOutputHelper output;

        public SimpleTypeTests(ITestOutputHelper output)
        {
            this.output = output;
        }

        [Fact] public void SByte() => Test((sbyte)1, (sbyte)99, (sbyte)0);
        [Fact] public void Byte() => Test((byte)1, (byte)99, (byte)0);
        [Fact] public void Int16() => Test((short)1, (short)99, (short)0);
        [Fact] public void UInt16() => Test((ushort)1, (ushort)99, (ushort)0);
        [Fact] public void Int32() => Test((int)1, (int)99, (int)0);
        [Fact] public void UInt32() => Test((uint)1, (uint)99, (uint)0);
        [Fact] public void Int64() => Test((long)1, (long)99, (long)0);
        [Fact] public void UInt64() => Test((ulong)1, (ulong)99, (ulong)0);
        [Fact] public void Char() => Test('a', 'z', 'x');
        [Fact] public void Single() => Test((float)1.5, (float)99.5, (float)0.5);
        [Fact] public void Double() => Test((double)1.5, (double)99.5, (double)0.5);
        [Fact] public void Boolean() => Test(false, true, false);
        [Fact] public void Decimal() => Test((decimal)1.5, (decimal)99.5, (decimal)0.5);

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