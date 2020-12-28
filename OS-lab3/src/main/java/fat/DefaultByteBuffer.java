package fat;

import lombok.Data;
import lombok.NoArgsConstructor;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;

@Data
@NoArgsConstructor
public class DefaultByteBuffer {
    protected ByteBuffer byteBuffer;

    public DefaultByteBuffer(int size) {
        byteBuffer = ByteBuffer.allocate(size);
        byteBuffer.order(ByteOrder.LITTLE_ENDIAN);
    }

    public DefaultByteBuffer(byte[] buffer) {
        byteBuffer.put(buffer);
    }

    public void append(byte el) {
        byteBuffer.put(el);
    }
}
